class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        vector<int> unionArr; // Your temporary storage

        // 1. Compare and add the smaller element to unionArr
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                unionArr.push_back(nums1[i]);
                i++;
            } else {
                unionArr.push_back(nums2[j]);
                j++;
            }
        }

        // 2. Add remaining elements from nums1 (if any)
        while (i < m) {
            unionArr.push_back(nums1[i]);
            i++;
        }

        // 3. Add remaining elements from nums2 (if any)
        while (j < n) {
            unionArr.push_back(nums2[j]);
            j++;
        }

        // 4. Copy the sorted elements back into nums1
        for (int k = 0; k < m + n; k++) {
            nums1[k] = unionArr[k];
        }
    }
};