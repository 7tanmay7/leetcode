class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, minutes = 0;
        // Add all rotten oranges to queue, count fresh ones
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;

        // Directions
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty() && fresh) {
            int sz = q.size();
            while(sz--) {
                auto [x, y] = q.front(); q.pop();
                for(auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1) {
                        grid[nx][ny]=2; fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            minutes++;
        }
        return fresh ? -1 : minutes;
    }
};