class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge; // Stores next greater for each element in nums2
        stack<int> st;

        // Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            // If stack is empty, no greater element to the right
            if (st.empty()) nge[num] = -1;
            else nge[num] = st.top();

            st.push(num);
        }

        // Build the answer for nums1 using the map
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            ans.push_back(nge[nums1[i]]);
        }
        return ans;
    }
};