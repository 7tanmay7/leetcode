#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // Handle edge cases for empty matrices
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Start pointer at the top-right corner
        int row = 0;
        int col = cols - 1;

        // Traverse while within the matrix boundaries
        while (row < rows && col >= 0) {
            int current_val = matrix[row][col];

            if (current_val == target) {
                return true;          // Target found
            } else if (current_val > target) {
                col--;                // Move left
            } else {
                row++;                // Move down
            }
        }

        return false;                 // Target not found
    }
};