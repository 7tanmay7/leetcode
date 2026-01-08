class Solution {
public:
    long long totalSum = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val
             + getTotalSum(root->left)
             + getTotalSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        long long product = subSum * (totalSum - subSum);
        ans = max(ans, product);

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return ans % MOD;
    }
};
