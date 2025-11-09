class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;
            int maxRow = 0;
            // Find the row with the max value in midCol
            for (int i = 0; i < m; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int leftVal = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int rightVal = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;
            int currVal = mat[maxRow][midCol];

            if (currVal > leftVal && currVal > rightVal) {
                return {maxRow, midCol};
            } else if (leftVal > currVal) {
                right = midCol - 1;
            } else {
                left = midCol + 1;
            }
        }
        return {-1, -1}; // Should never reach here
    }
};