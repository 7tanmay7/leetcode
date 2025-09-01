class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // k will track the position for non-val elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move non-val element to the front
                k++;
            }
        }
        return k; // k is the count of elements not equal to val
    }
};