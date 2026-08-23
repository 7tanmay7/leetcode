class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxprod = nums[0];
        int minprod = nums[0];
        for(int i =1; i<nums.size();i++){
            int curr =nums[i];
            if(curr<0)
            swap(maxprod, minprod);
            maxprod = max(curr ,maxprod*curr);
            minprod = min(curr, minprod*curr);
            res = max(res ,maxprod);
        }
        return res;
    }
};