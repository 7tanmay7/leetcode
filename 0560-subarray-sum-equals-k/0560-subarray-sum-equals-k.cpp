class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> prefixSumCount;
        int count = 0;
        int prefixSum = 0;

        prefixSumCount[0] = 1; // To handle cases when prefixSum == k directly

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];

            // Check if there's a prefixSum that, when removed, gives sum == k
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }

            // Store or update the current prefixSum in the map
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};
