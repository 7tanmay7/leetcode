class Solution {
private:
    // DFS to mark 'O's connected to the boundary
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int delRow[], int delCol[]) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1; // Mark as visited
        board[row][col] = '#'; // Temporarily mark as safe

        // Traverse in 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            // Check bounds and if the next cell is unvisited 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, board, vis, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
        int delCol[] = {0, 1, 0, -1};

        // 1. Mark all 'O's on the boundary and their connected 'O's
        for (int j = 0; j < m; j++) {
            // First row
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis, delRow, delCol);
            // Last row
            if (board[n-1][j] == 'O' && !vis[n-1][j])
                dfs(n-1, j, board, vis, delRow, delCol);
        }
        for (int i = 0; i < n; i++) {
            // First column
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis, delRow, delCol);
            // Last column
            if (board[i][m-1] == 'O' && !vis[i][m-1])
                dfs(i, m-1, board, vis, delRow, delCol);
        }

        // 2. Flip all remaining 'O's to 'X', and '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X'; // Surrounded region
                else if (board[i][j] == '#')
                    board[i][j] = 'O'; // Safe region
            }
        }
    }
};