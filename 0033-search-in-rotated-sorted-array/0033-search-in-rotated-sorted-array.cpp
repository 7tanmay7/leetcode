#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // If target is found, return its index
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if the target lies within the sorted left half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Search left
                } else {
                    low = mid + 1;  // Search right
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Check if the target lies within the sorted right half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Search right
                } else {
                    high = mid - 1; // Search left
                }
            }
        }
        
        return -1; 
    }
};