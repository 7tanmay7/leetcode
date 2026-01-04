class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Work with positive values, remember the sign
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long result = 0;
        // First while: subtract divisor shifted as much as possible
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            // Second while: find the max shift
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }
        result *= sign;
        // Clamp result to 32-bit signed int range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return result;
    }
};