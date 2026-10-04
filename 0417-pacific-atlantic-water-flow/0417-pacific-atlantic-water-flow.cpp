#include <vector>

using namespace std;

class Solution {
private:
    int ROWS, COLS;

    void dfs(int r, int c, vector<vector<bool>>& visit, int prevHeight, const vector<vector<int>>& heights) {
        // Base cases: out of bounds, already visited, or height is smaller than previous cell
        if (r < 0 || c < 0 || r == ROWS || c == COLS || 
            visit[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        visit[r][c] = true;

        // Explore all 4 adjacent directions
        dfs(r + 1, c, visit, heights[r][c], heights);
        dfs(r - 1, c, visit, heights[r][c], heights);
        dfs(r, c + 1, visit, heights[r][c], heights);
        dfs(r, c - 1, visit, heights[r][c], heights);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // Top row (Pacific) and Bottom row (Atlantic)
        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pac, heights[0][c], heights);
            dfs(ROWS - 1, c, atl, heights[ROWS - 1][c], heights);
        }

        // Left column (Pacific) and Right column (Atlantic)
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pac, heights[r][0], heights);
            dfs(r, COLS - 1, atl, heights[r][COLS - 1], heights);
        }

        // Collect coordinates that can reach both oceans
        vector<vector<int>> res;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};