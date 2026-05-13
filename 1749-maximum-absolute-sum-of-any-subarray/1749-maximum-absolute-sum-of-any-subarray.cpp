class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize to 0 to handle the "possibly empty" subarray case
        int max_sum = 0; 
        int min_sum = 0;
        
        int current_max = 0;
        int current_min = 0;

        for (int i = 0; i < n; i++) {
            // 1. Fix: Use += to accumulate the sum
            current_max += nums[i];
            // Standard Kadane: if sum is negative, reset to 0
            if (current_max < 0) current_max = 0;
            max_sum = max(max_sum, current_max);

            // 2. Track the most negative sum
            current_min += nums[i];
            // if sum is positive, reset to 0
            if (current_min > 0) current_min = 0;
            min_sum = min(min_sum, current_min);
        }

        // 3. Fix: Return must be OUTSIDE the for loop
        return max(max_sum, abs(min_sum));
    }
};