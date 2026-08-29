class Solution {
private:
    void recursiveInorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        
        recursiveInorder(root->left, arr);
        arr.push_back(root->val); 
        recursiveInorder(root->right, arr);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        recursiveInorder(root, arr);
        return arr; 
    }
};