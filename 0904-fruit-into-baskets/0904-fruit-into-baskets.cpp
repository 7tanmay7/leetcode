class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
    int low = 0;
    int res = 0;
    unordered_map<int, int> f; // Frequency map for fruit types

    for (int high = 0; high < n; high++) {
        // Add the current fruit to the frequency map
        f[fruits[high]]++;

        // While the map size is greater than 2, remove elements from the left (low)
        while (f.size() > 2) {
            int left_fruit = fruits[low];
            f[left_fruit]--;

            // If the count of that fruit hits 0, remove the key from the map
            if (f[left_fruit] == 0) {
                f.erase(left_fruit);
            }
            
            low++; // Increment low to shrink the window
        }

        // Calculate maximum window size found so far
        res = max(res, high - low + 1);
    }

    return res;
}
    
};