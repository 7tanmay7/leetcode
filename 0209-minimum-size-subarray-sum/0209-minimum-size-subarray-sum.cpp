class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minLen = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            // Shrink window from the left as long as sum >= target
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};