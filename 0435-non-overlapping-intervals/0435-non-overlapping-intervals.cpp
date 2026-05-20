#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Must be static to be used inside std::sort without an object instance
    static bool comp(const vector<int>& val1, const vector<int>& val2) {
        return val1[1] < val2[1]; // Sort by end times ascending
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int keep_cnt = 1; 
        int last_end_time = intervals[0][1];
        int n = intervals.size();
        
        
        for (int i = 1; i < n; i++) {
            // If the current interval starts after or when the last one ends, they don't overlap
            if (intervals[i][0] >= last_end_time) {
                keep_cnt++;
                last_end_time = intervals[i][1]; 
            }
        }
        
        // 3. Minimum removals = Total intervals - Max intervals we can keep
        return n - keep_cnt;
    }
};