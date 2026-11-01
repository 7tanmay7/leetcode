class Solution {
public:
   bool check(vector<int>& nums, vector<int>& sortedNums, int st, int k) {
        int d = -1;

        for(int i = st; i < st + k - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                if(d != -1) return false;
                d = i - st;
            }
        }

        if(d == -1) {
            for(int i = 0; i < k; i++) {
                if(nums[st + i] != sortedNums[st + i])
                    return false;
            }
            return true;
        }

        for(int i = 0; i <= d; i++) {
            if(nums[st + i] != sortedNums[st + k - d - 1 + i])
                return false;
        }

        for(int i = d + 1; i < k; i++) {
            if(nums[st + i] != sortedNums[st + i - d - 1])
                return false;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for(int k = 1; k <= n; k++) {
            if(n % k != 0) continue;

            bool flag = true;

            for(int i = 0; i < n; i += k) {
                if(!check(nums, sortedNums, i, k)) {
                    flag = false;
                    break;
                }
            }

            if(flag) ans += k;
        }

        return ans;
    }
};