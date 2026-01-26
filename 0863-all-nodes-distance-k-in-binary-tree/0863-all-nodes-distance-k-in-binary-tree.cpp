class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        mapParentNodes(root, parentMap);
        return bfsFromTarget(target, parentMap, k);
    }

private:
    // Build a mapping from each node to its parent node
    void mapParentNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // BFS from the target node to find all nodes at distance k
    vector<int> bfsFromTarget(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentLevel++ == k) break;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()) {
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};