class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            // Compare last element of current row with target
            if (matrix[i][n - 1] >= target) {
                // Binary search in this row
                int left = 0, right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] == target) return true;
                    else if (matrix[i][mid] < target) left = mid + 1;
                    else right = mid - 1;
                }
                // If not found in this row, no need to check further
                return false;
            }
        }
        // If target is greater than all last elements
        return false;
    }
};