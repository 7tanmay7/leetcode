class Solution {
private:
    void dfs(vector<vector<char>>& g, int r, int c) {
        if (r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c] != '1') 
            return;
        
        g[r][c] = '0'; // Mark land as visited
        
        // Visit all 4 adjacent neighbors
        dfs(g, r + 1, c);
        dfs(g, r - 1, c);
        dfs(g, r, c + 1);
        dfs(g, r, c - 1);
    }

public:
    int numIslands(vector<vector<char>>& g) { // Renamed parameter from 'grid' to 'g'
        int ans = 0;
        for (int r = 0; r < g.size(); r++) {
            for (int c = 0; c < g[0].size(); c++) {
                if (g[r][c] == '1') {
                    ans++;
                    dfs(g, r, c);
                }
            }
        }
        return ans;
    }
};