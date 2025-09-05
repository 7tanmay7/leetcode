class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

        // Skip leading whitespace
        while (i < s.size() && s[i] == ' ') i++;

        // Check sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Convert digits
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Handle overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return (int)(result * sign);
    }
};
