
class Solution {
      private :
      void recursivePreorder(TreeNode*root, vector<int>& arr){
        if(root == nullptr){
            return;
        }
        arr.push_back(root->val); 
        recursivePreorder(root->left , arr);
         recursivePreorder(root->right , arr);
      }

      public:
      vector<int>preorderTraversal(TreeNode* root) {
        vector<int> arr;
        recursivePreorder(root, arr);
        return arr; 
    }
};