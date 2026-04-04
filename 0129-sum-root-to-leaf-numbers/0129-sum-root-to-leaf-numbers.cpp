class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;

        // Calculate the number represented by the path so far
        currentSum = currentSum * 10 + node->val;

        // If it's a leaf node, return the path sum
        if (!node->left && !node->right) {
            return currentSum;
        }

        // Recursively sum the values from left and right subtrees
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};