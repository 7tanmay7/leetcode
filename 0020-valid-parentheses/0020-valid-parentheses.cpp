#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         unordered_map<char, char> mp = {
//             {')', '('},
//             {'}', '{'},
//             {']', '['}
//         };

//         for (char c : s) {
//             if (mp.count(c)) {
//                 if (st.empty() || st.top() != mp[c]) {
//                     return false;
//                 }
//                 st.pop();
//             } else {
//                 st.push(c);
//             }
//         }

//         return st.empty();
//     }
// };