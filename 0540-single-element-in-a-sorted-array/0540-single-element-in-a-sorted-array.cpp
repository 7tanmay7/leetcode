#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            
            // m ^ 1 cleanly checks the correct duplicate partner index:
            // - If m is even, m ^ 1 is m + 1
            // - If m is odd, m ^ 1 is m - 1
            if (nums[m] == nums[m ^ 1]) {
                l = m + 1; 
            } else {
                r = m;                 }
        }
        
        return nums[l];
    }
};