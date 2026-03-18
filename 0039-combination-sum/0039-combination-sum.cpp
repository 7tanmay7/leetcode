class Solution {
public:

    void solve(int i, vector<int>& arr, int target, 
               vector<int>& ds, vector<vector<int>>& ans) {

        // ✅ Base Case: target achieved
        if(target == 0) {
            ans.push_back(ds); // store current combination
            return;
        }

        // ❌ Base Case: out of bounds
        if(i == arr.size()) return;

        // 🔥 PICK CASE
        // Only pick if element is <= target
        if(arr[i] <= target) {
            ds.push_back(arr[i]); // include element

            // Stay at same index (because reuse allowed)
            solve(i, arr, target - arr[i], ds, ans);

            ds.pop_back(); // backtrack (remove last element)
        }

        // ❌ NOT PICK CASE
        // Move to next index
        solve(i+1, arr, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, candidates, target, ds, ans);

        return ans;
    }
};