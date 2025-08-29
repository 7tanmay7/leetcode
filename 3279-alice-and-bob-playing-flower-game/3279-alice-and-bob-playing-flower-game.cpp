class Solution {
public:
    long long flowerGame(int n, int m) {
        // Alice wins if x + y is odd (since she starts first)
        // Count pairs (x, y) where x in [1, n], y in [1, m], and x + y is odd

        long long odd_n = (n + 1) / 2;
        long long even_n = n / 2;
        long long odd_m = (m + 1) / 2;
        long long even_m = m / 2;

        // x odd + y even, or x even + y odd
        return odd_n * even_m + even_n * odd_m;
    }
};