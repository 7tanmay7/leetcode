class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0); // for all ASCII characters
        int n = s.size();
        int left = 0, right = 0, total = 0;

        while (right < n) {
            // If s[right] is already in the window, shrink from left
            while (count[s[right]] > 0) {
                count[s[left]]--;
                left++;
            }
            count[s[right]]++;
            total = max(total, right - left + 1);
            right++;
        }
        return total;
    }
};
