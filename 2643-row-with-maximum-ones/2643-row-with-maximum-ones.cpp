class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();      
        int n = mat[0].size();   
        
        int maxOnes = -1;
        int maxRowIndex = 0;
        
        for (int i = 0; i < m; i++) {
            int currentOnes = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    currentOnes++;
                }
            }
            if (currentOnes > maxOnes) {
                maxOnes = currentOnes;
                maxRowIndex = i;
            }
        }
        
        return {maxRowIndex, maxOnes};
    }
};