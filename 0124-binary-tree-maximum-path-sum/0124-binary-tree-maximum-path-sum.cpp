class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        pathSum(root, maxSum);
        return maxSum;
    }

    int pathSum(TreeNode* root, int &maxSum) {
        if (!root) return 0;

        int left = max(0, pathSum(root->left, maxSum));   // Ignore negatives
        int right = max(0, pathSum(root->right, maxSum)); // Ignore negatives

        // Update maxSum: may pass through root (left + root + right)
        maxSum = max(maxSum, root->val + left + right);

        // Return max single path upward
        return root->val + max(left, right);
    }
};
