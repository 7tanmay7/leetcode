class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // Remove from the end if k > 0
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Build the result string
        string result;
        for (char c : st) {
            if (result.empty() && c == '0') continue; // Skip leading zeros
            result.push_back(c);
        }

        return result.empty() ? "0" : result;
    }
};