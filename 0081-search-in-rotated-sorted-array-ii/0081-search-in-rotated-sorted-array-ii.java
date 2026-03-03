class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int start =0 , end = n-1;
        while(start<=end){
            int mid = start + (end- start)/2;
            if(nums[mid]== target){
                return true;
            }
            if(nums[mid]== nums[start]){
                start++;
                continue;
            }
            // left
            if(nums[mid]>=nums[start]){
                if(target>= nums[start] && target < nums[mid]){
                    end = mid -1;
                } else{
                    start = mid+1;
                }
            }
            // right
            else {
                if(target <=nums[end] && target > nums [mid]) {
                    start = mid+1;
                }else {
                    end = mid -1;
                }
            }
        }
        return false;
    }
}