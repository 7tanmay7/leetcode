#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(2048, false)));
        
        int minVal = INT_MAX;
        dfs(grid, 0, 0, 0, minVal, visited);
        
        return minVal;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, int currXor, int& minVal, vector<vector<vector<bool>>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n) {
            return;
        }

        currXor ^= grid[i][j];

        if (visited[i][j][currXor]) {
            return;
        }
        
        visited[i][j][currXor] = true;

        if (i == m - 1 && j == n - 1) {
            minVal = min(minVal, currXor);
            return;
        }

        dfs(grid, i, j + 1, currXor, minVal, visited);
        dfs(grid, i + 1, j, currXor, minVal, visited);
    }
};

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid) {
//         int minVal = INT_MAX;
//         dfs(grid, 0, 0, 0, minVal);
//         return minVal;
//     }

// private:
//     void dfs(vector<vector<int>>& grid, int i, int j, int currXor, int& minVal) {
//         int m = grid.size();
//         int n = grid[0].size();

//         if (i >= m || j >= n) {
//             return;
//         }

//         currXor ^= grid[i][j];

//         if (i == m - 1 && j == n - 1) {
//             minVal = min(minVal, currXor);
//             return;
//         }

//         dfs(grid, i, j + 1, currXor, minVal);
//         dfs(grid, i + 1, j, currXor, minVal);
//     }
// };