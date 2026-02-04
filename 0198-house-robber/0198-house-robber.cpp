class Solution {
public:
    int fmemo(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0)
            return 0;
        if (i == 0)
            return dp[i] = nums[i];
        if (dp[i] != -1)
            return dp[i];
        int take = nums[i] + fmemo(i - 2, nums, dp);
        int notake = fmemo(i - 1, nums, dp);
        return dp[i] = max(take, notake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fmemo(n - 1, nums, dp);
    }
};