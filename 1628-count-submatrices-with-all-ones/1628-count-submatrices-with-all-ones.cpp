class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<vector<int>> left(m, vector<int>(n, 0));
        // Precompute consecutive ones to the left
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                left[i][j] = mat[i][j] ? (j == 0 ? 1 : left[i][j-1] + 1) : 0;

        // For each cell, count rectangles ending at (i, j)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (!mat[i][j]) continue;
                int min_width = left[i][j];
                for (int k = i; k >= 0 && min_width; --k) {
                    min_width = min(min_width, left[k][j]);
                    res += min_width;
                }
            }
        return res;
    }
};