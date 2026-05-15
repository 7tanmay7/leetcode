class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int low = 0;
        int res = 0;
        unordered_map<char, int> f; // Frequency map

        for (int high = 0; high < n; high++) {
            // Add the current character to the map
            f[s[high]]++;

            // If the current character is a duplicate, shrink from the left
            // until the count of s[high] is back to 1
            while (f[s[high]] > 1) {
                char left_char = s[low];
                f[left_char]--;
                
                // Optional: remove key if count is 0 to keep map clean
                if (f[left_char] == 0) {
                    f.erase(left_char);
                }

                low++; // Move the left pointer forward
            }

            // Calculate maximum window size (all characters are now unique)
            res = max(res, high - low + 1);
        }

        return res;
    }
};