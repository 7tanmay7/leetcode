class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        int row = 0, col = 0, dir = 1;
        for (int i = 0; i < m * n; ++i) {
            res.push_back(mat[row][col]);
            if (dir == 1) { // moving up
                if (col == n - 1) { row++; dir = -1; }
                else if (row == 0) { col++; dir = -1; }
                else { row--; col++; }
            } else { // moving down
                if (row == m - 1) { col++; dir = 1; }
                else if (col == 0) { row++; dir = 1; }
                else { row++; col--; }
            }
        }
        return res;
    }
};