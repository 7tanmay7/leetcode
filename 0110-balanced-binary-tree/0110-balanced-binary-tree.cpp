class Solution {
    public:
    int getHeight (TreeNode* root){
        if(!root)
        return 0;
        int left = getHeight(root->left);
        if(left==-1)
        return -1; //left is not balanced
        int right = getHeight(root->right);
        if(right==-1)
        return -1;
        if (abs(left-right) >1)
        return -1;
        return 1+ std::max(left, right);

    }
    bool isBalanced(TreeNode* root){
        return getHeight(root) !=-1;
    }
};