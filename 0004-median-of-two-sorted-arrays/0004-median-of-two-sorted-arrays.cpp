class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int target = total / 2;
        
        int i = 0, j = 0;
        int prev = 0, curr = 0;
        
        // Move pointers to find median position(s)
        for(int count = 0; count <= target; count++) {
            prev = curr;
            
            if(i < m && (j >= n || nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
        }
        
        if(total % 2 == 1) {
            return (double)curr;
        } else {
            return (prev + curr) / 2.0;
        }
    }
};