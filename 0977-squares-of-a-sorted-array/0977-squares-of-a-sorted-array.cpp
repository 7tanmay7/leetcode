class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> result(n);
        int i =0; int j= n-1;

        for(int k = n-1; k>=0 ; k--){
            if(abs(nums[i])>abs(nums[j])){
                result[k]= nums[i] * nums[i];
                i++;
            }
            else{
                result[k]= nums[j]* nums[j];
                j--;
            }
        }
        return result;
        
    }
};