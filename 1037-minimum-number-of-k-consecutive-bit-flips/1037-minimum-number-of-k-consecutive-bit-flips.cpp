class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> flips; // stores indices where flips start
        int res = 0;
        for(int i = 0; i < n; ++i) {
            // Remove flips that are out of window
            if(!flips.empty() && flips.front() == i - k) flips.pop_front();
            // If flips.size() is odd, current bit is flipped odd times
            if((nums[i] + flips.size()) % 2 == 0) {
                if(i + k > n) return -1;
                flips.push_back(i);
                res++;
            }
        }
        return res;
    }
};