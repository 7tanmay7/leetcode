#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if we can make 'm' bouquets on a given 'day'
    bool isValid(vector<int>& arr, int day, int m, int k) {
        int cnt = 0;
        int bq = 0; // number of bouquets formed

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                cnt++; // flower has bloomed, increment adjacent count
            } else {
                bq += (cnt / k); // form bouquets from consecutive bloomed flowers
                cnt = 0;         // reset counter since adjacency is broken
            }
        }
        bq += (cnt / k); // catch any remaining bouquets at the end of the array
        
        return bq >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        // Overflow prevention: use long long for the product
        if ((long long)m * k > n) return -1;

        // Find the range for binary search
        int low = bloomDay[0];
        int high = bloomDay[0];
        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        int ans = high;

        // Binary search on answer range
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(bloomDay, mid, m, k)) {
                ans = mid;       // 'mid' is a potential answer
                high = mid - 1;  // Try to find a smaller number of days
            } else {
                low = mid + 1;   // 'mid' is too small, look for more days
            }
        }

        return ans;
    }
};