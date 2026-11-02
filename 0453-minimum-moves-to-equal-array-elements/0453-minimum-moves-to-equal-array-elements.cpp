class Solution {
public:
    int minMoves(vector<int>& nums) {
  int mn=nums[0];
  for(int i=0;i<nums.size();i++){
    if(nums[i]<mn)
    mn=nums[i];
  }
  int s=0;
  for(int i=0;i<nums.size();i++){
    s+=nums[i]-mn;
  }
  return s;
    }
};