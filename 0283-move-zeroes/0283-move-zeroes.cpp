class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;

        // Step 1: Find the index of the first 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // If there's no zero, array is already fine
        if (j == -1) return;

        // Step 2: From the next index, look for non-zero and swap with j
        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++; // Move j to next zero
            }
        }
    }
};
