class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int res = 0;
        // Try jumping every other stone (greedy, as per problem's optimal path)
        for (int i = 2; i < n; ++i) {
            res = max(res, stones[i] - stones[i - 2]);
        }
        // Also consider the first jump (from 0 to 1) and last jump (n-2 to n-1)
        for (int i = 1; i < n; ++i) {
            res = max(res, stones[i] - stones[i - 1]);
        }
        return res;
    }
};
