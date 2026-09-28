#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solveMemo(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
        // Base case: if we reach the end of either string
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        
        // Return precomputed result if available
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // If characters match, include it and move both pointers
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solveMemo(i + 1, j + 1, text1, text2, dp);
        }
        
        // If characters don't match, take the maximum of skipping either character
        int skipText1 = solveMemo(i + 1, j, text1, text2, dp);
        int skipText2 = solveMemo(i, j + 1, text1, text2, dp);
        
        return dp[i][j] = max(skipText1, skipText2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        // Initialize 2D DP table with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solveMemo(0, 0, text1, text2, dp);
    }
};