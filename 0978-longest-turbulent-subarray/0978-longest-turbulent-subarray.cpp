class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return n;

        int maxLen = 1;
        int l = 0;
        int prev = 0;

        for (int r = 1; r < n; ++r) {
            int current = 0;
            if (arr[r - 1] < arr[r]) {
                current = -1;
            } else if (arr[r - 1] > arr[r]) {
                current = 1;
            }

            if (current == 0) {
                l = r;
            } else if (current == prev) {
                l = r - 1;
            }
            
            maxLen = max(maxLen, r - l + 1);
            prev = current;
        }

        return maxLen;
    }
};