class Solution {
public:
    int minDepth(TreeNode* root) {
        // If the tree is empty
        if (!root) return 0;

        // If left child is NULL, recurse only on right child
        if (!root->left) return 1 + minDepth(root->right);

        // If right child is NULL, recurse only on left child
        if (!root->right) return 1 + minDepth(root->left);

        // If both children exist, take the minimum depth of both sides
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};