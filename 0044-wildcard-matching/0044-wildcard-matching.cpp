class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0, lastWildcardIdx = -1, sBacktrackIdx = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            // Case 1: Characters match or pattern has '?'
            if (pIdx < pLen && (p[pIdx] == s[sIdx] || p[pIdx] == '?')) {
                sIdx++;
                pIdx++;
            } 
            // Case 2: Pattern has '*'
            else if (pIdx < pLen && p[pIdx] == '*') {
                lastWildcardIdx = pIdx;
                sBacktrackIdx = sIdx;
                pIdx++; // Advance pattern, assume '*' matches empty sequence first
            } 
            // Case 3: No match, but we saw a '*' earlier
            else if (lastWildcardIdx != -1) {
                pIdx = lastWildcardIdx + 1; // Reset pattern to just after the '*'
                sBacktrackIdx++;            // '*' now matches one more character in s
                sIdx = sBacktrackIdx;
            } 
            // Case 4: No match and no '*' to fall back on
            else {
                return false;
            }
        }

        // Check for remaining '*' in pattern
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};