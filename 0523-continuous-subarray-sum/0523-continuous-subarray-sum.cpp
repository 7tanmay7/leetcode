class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndex;
        modIndex[0] = -1;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int mod;
            if (k != 0) {
                mod = prefixSum % k;
            } else {
                mod = prefixSum;
            }

            if (modIndex.count(mod)) {
                if (i - modIndex[mod] >= 2) {
                    return true;
                }
            } else {
                modIndex[mod] = i;
            }
        }
        return false;
    }
};