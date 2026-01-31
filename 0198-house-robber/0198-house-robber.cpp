class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        long long int prev = nums[0];
        long long int prev2 = 0;

        for (int i = 1; i < n; i++) {
            long long int pick = nums[i];
            if (i > 1) pick += prev2;
            long long int nonPick = prev;
            long long int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }
};