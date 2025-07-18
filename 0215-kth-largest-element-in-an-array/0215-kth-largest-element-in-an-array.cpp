class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()); // Sort in descending order
        return nums[k - 1]; // Return the K-th largest
    }
};
