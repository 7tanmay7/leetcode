
class Solution {
public:
    int maxDepth (TreeNode* root , int&maxi){
        if(root== nullptr)return 0;
        int left = maxDepth(root->left,maxi);
        int right =maxDepth(root->right,maxi);
        maxi =std::max(maxi,left+right);
        return 1+ std::max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root){
        int maxi=0;
        maxDepth(root,maxi);
        return maxi;
    }
};