class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        int xor1 = 0, xor2 = 0;

        // XOR of all array elements
        for (int i = 0; i < n; i++) {
            xor1 ^= a[i];
        }

        // XOR of all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor2 ^= i;
        }

        return xor1 ^ xor2;
    }
};
