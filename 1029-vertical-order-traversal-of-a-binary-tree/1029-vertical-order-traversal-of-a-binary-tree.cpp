class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        const int OFFSET = 1000;  // to handle negative indices
        const int WIDTH = 2001;   // range: -1000 to +1000
        vector<vector<int>> cols(WIDTH);

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});  // root at col = 0

        int l = 0, r = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<pair<int, int>> level;  // (col, val)

            for (int i = 0; i < size; i++) {
                auto [node, col] = q.front();
                q.pop();

                level.push_back({col, node->val});

                // update leftmost and rightmost column boundaries
                l = min(l, col);
                r = max(r, col);

                if (node->left) q.push({node->left, col - 1});
                if (node->right) q.push({node->right, col + 1});
            }

            // sort level nodes by column and value (for vertical + level order)
            sort(level.begin(), level.end());

            for (auto& [col, val] : level) {
                cols[col + OFFSET].push_back(val);
            }
        }

        // extract final result from columns between l and r
        vector<vector<int>> result;
        for (int i = l + OFFSET; i <= r + OFFSET; i++) {
            if (!cols[i].empty())
                result.push_back(cols[i]);
        }

        return result;
    }
};
