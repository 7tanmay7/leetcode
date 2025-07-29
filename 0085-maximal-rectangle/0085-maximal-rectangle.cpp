class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxRect = 0;

        for (int i = 0; i < m; ++i) {
            // Update histogram height
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            // Compute max rectangle in histogram
            maxRect = max(maxRect, largestRectangleArea(heights));
        }

        return maxRect;
    }
};
