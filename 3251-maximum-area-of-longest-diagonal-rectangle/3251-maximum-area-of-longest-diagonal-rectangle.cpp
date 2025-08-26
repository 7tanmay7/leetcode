class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0, maxArea = 0;
        for (auto& rect : dimensions) {
            int l = rect[0], w = rect[1];
            int diagSq = l*l + w*w;
            int area = l * w;
            if (diagSq > maxDiag) {
                maxDiag = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};