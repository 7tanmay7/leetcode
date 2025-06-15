class Solution {
public:
    // Map to store parent of each node
    unordered_map<TreeNode*, TreeNode*> parentMap;

    // Step 1: Build parent mapping using DFS
    void markParents(TreeNode* root, TreeNode* parent) {
        if (!root) return;
        parentMap[root] = parent;
        markParents(root->left, root);
        markParents(root->right, root);
    }

    // Step 2: BFS from target to find nodes at distance K
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root, nullptr);  // Build parent mapping

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int currDist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currDist == k) break;  // Stop when distance = k
            currDist++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();

                // Traverse left
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                // Traverse right
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                // Traverse parent
                TreeNode* parent = parentMap[node];
                if (parent && !visited.count(parent)) {
                    visited.insert(parent);
                    q.push(parent);
                }
            }
        }

        // Collect all nodes at distance k
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
