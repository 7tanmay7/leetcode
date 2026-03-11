class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = n - 1;

        while(left <= right){

            int mid = (left + right) / 2;

            int maxRow = 0;

            for(int i = 0; i < m; i++){
                if(mat[i][mid] > mat[maxRow][mid]){
                    maxRow = i;
                }
            }

            int leftVal = -1;
            int rightVal = -1;

            if(mid - 1 >= 0)
                leftVal = mat[maxRow][mid - 1];

            if(mid + 1 < n)
                rightVal = mat[maxRow][mid + 1];

            if(mat[maxRow][mid] > leftVal && mat[maxRow][mid] > rightVal){
                return {maxRow, mid};
            }
            else if(rightVal > mat[maxRow][mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return {-1,-1};
    }
};