// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         long long sum = 0;
//         int n = arr.size();
//         int MOD = 1e9 + 7;

//         for (int i = 0; i < n; i++) {
//             int minm = arr[i];
//             for (int j = i; j < n; j++) {
//                 minm = min(minm, arr[j]);
//                 sum = (sum + minm) % MOD;
//             }
//         }

//         return sum;
//     }
// };
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> s;

        // Previous Smaller Element (strictly less)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for next computation
        while (!s.empty()) s.pop();

        // Next Smaller Element (less than or equal)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long sum = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            sum = (sum + (arr[i] * left % mod) * right % mod) % mod;
        }

        return sum;
    }
};
