class Solution {
public:
    int count = 0;       // To track how many nodes we've visited
    int result = -1;     // To store the kth smallest value

    void inorder(TreeNode* root, int k) {
        if (!root || count >= k) return;

        inorder(root->left, k); // Left subtree

        count++;
        if (count == k) {
            result = root->val; // Found the kth smallest
            return;
        }

        inorder(root->right, k); // Right subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};