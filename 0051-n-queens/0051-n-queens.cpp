class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);       // columns
        vector<bool> diag1(2 * n - 1, false); // row - col + n - 1
        vector<bool> diag2(2 * n - 1, false); // row + col

        backtrack(0, n, board, res, cols, diag1, diag2);
        return res;
    }

    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& res,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;

            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

            backtrack(row + 1, n, board, res, cols, diag1, diag2);

            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
};
