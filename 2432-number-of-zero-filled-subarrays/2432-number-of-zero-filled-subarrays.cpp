class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, result = 0;
        for (int num : nums) {
            if (num == 0) {
                count++; // Increase count of consecutive zeros
                result += count; // Add to result: all subarrays ending here
            } else {
                count = 0; // Reset count if non-zero
            }
        }
        return result;
    }
};