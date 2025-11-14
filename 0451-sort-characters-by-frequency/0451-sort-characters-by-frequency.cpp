class Solution {
public:
    string frequencySort(string s) {
        // Frequency array for all ASCII characters
        vector<pair<int, char>> freq(128);
        for (int i = 0; i < 128; ++i) {
            freq[i] = make_pair(0, (char)i);
        }
        // Count frequencies
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            freq[(int)ch].first++;
        }
        // Sort by frequency descending
        sort(freq.begin(), freq.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first;
        });
        // Build answer string
        string ans;
        for (int i = 0; i < freq.size(); ++i) {
            for (int j = 0; j < freq[i].first; ++j) {
                ans += freq[i].second;
            }
        }
        return ans;
    }
};