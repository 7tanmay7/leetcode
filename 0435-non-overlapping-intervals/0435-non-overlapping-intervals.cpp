#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 1. Custom comparator using Striver's logic
    // Sorts the intervals based on their END values in ascending order
    static bool comp(const vector<int>& val1, const vector<int>& val2) {
        return val1[1] < val2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 2. Sort the entire array using the custom comparator
        sort(intervals.begin(), intervals.end(), comp);

        // 3. Keep track of non-overlapping intervals (cit)
        int countNonOverlapping = 1;
        int lastEndTime = intervals[0][1];

        // 4. Iterate through the remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If the next interval starts after or exactly when the last one ends
            if (intervals[i][0] >= lastEndTime) {
                countNonOverlapping++;
                lastEndTime = intervals[i][1]; // Move the pointer to the new end time
            }
        }

        // 5. Total intervals to remove = Total - Count of non-overlapping pairs
        return intervals.size() - countNonOverlapping;
    }
};