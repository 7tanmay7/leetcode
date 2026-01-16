class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Push all boundary land cells into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check if cell is on the boundary and is land
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        // BFS to mark all land cells connected to the boundary
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];
                // Check bounds, unvisited, and land
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        // Count the number of unvisited land cells (enclaves)
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};