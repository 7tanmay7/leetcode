class Solution {
private:
    // Helper function to calculate the total sum for a given divisor
    bool isValidDivisor(const std::vector<int>& nums, int divisor, int threshold) {
        long long sum = 0;
        for (int num : nums) {
            // Ceiling division: (num + divisor - 1) / divisor
            sum += (num + divisor - 1) / divisor;
        }
        return sum <= threshold;
    }

public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int low = 1;
        int high = *std::max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValidDivisor(nums, mid, threshold)) {
                ans = mid;       // Try to find a smaller divisor
                high = mid - 1;
            } else {
                low = mid + 1;   // The divisor is too small, increase it
            }
        }
        return ans;
    }
};