class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node) return;
        
        // Add current node value to path
        if (!path.empty()) path += "->";
        path += to_string(node->val);
        
        // If it's a leaf, add path to result
        if (!node->left && !node->right) {
            res.push_back(path);
            return;
        }
        
        // Recurse left and right
        dfs(node->left, path, res);
        dfs(node->right, path, res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};