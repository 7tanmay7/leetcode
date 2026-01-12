class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Step 1: Push all 0s into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1; // Mark as visited
                }
            }
        }

        // Directions: up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Step 2: BFS to update distances
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            for(int k = 0; k < 4; k++) {
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];
                // If inside bounds and not visited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return dist;
    }
};
    