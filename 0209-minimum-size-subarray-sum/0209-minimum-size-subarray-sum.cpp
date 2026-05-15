class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int sum = 0;
        int result = INT_MAX; // Initialize with a large value

        while (high < n) {
            // Expand the window by adding the element at 'high'
            sum += nums[high];

            // Shrink the window from the left as long as the condition is met
            while (sum >= target) {
                result = min(result, high - low + 1);
                sum -= nums[low];
                low++;
            }

            high++;
        }

        // If result was never updated, return 0
        return (result == INT_MAX) ? 0 : result;
    }
};