#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0; 
        int res = 0;
        int zeroCount = 0;

        // Use high < n in the loop condition
        for (int high = 0; high < n; ++high) {
            // Expand: Add the current element to the window
            if (nums[high] == 0) {
                zeroCount++;
            }

            // Contract: If we've used more than k flips, move 'low'
            while (zeroCount > k) {
                if (nums[low] == 0) {
                    zeroCount--;
                }
                low++;
            }

            // Update: Calculate the max window size seen so far
            res = max(res, high - low + 1);
        }

        return res;
    }
};