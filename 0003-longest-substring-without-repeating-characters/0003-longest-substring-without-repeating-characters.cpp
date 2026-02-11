class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxLen = 0, start = 0;
        for (int end = 0; end < s.length(); ++end) {
            if (lastSeen.count(s[end]) && lastSeen[s[end]] >= start) {
                start = lastSeen[s[end]] + 1;
            }
            lastSeen[s[end]] = end;
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};