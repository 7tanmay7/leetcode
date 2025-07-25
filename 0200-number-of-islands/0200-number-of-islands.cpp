class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
        // Base case
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0'; // Mark visited

        // 4 directions: up, down, left, right
        dfs(i - 1, j, grid, n, m); // up
        dfs(i + 1, j, grid, n, m); // down
        dfs(i, j - 1, grid, n, m); // left
        dfs(i, j + 1, grid, n, m); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, n, m);
                }
            }
        }

        return count;
    }
};

