class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n--);
        int op = 0;
        while (n) {
            if (op % 4 == 0) st.top() *= n;
            else if (op % 4 == 1) st.top() /= n;
            else if (op % 4 == 2) st.push(n);
            else st.push(-n);
            op++; n--;
        }
        int res = 0;
        while (!st.empty()) { res += st.top(); st.pop(); }
        return res;
    }
};