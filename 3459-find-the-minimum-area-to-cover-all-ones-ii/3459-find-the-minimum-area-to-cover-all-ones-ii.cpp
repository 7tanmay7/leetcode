
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Calculate area of bounding rectangle covering all 1's in the rectangle defined by (r1, c1) - (r2, c2)
        auto area = [&](int r1, int c1, int r2, int c2) {
            int min_r = m, max_r = -1, min_c = n, max_c = -1;
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    if (grid[r][c] == 1) {
                        min_r = min(min_r, r);
                        max_r = max(max_r, r);
                        min_c = min(min_c, c);
                        max_c = max(max_c, c);
                    }
                }
            }
            if (max_r == -1) return 0; // no 1's in this rectangle
            return (max_r - min_r + 1) * (max_c - min_c + 1);
        };

        int ans = INT_MAX;

        // Try 3 horizontal stripes
        for (int r1 = 0; r1 < m - 2; ++r1) {
            for (int r2 = r1 + 1; r2 < m - 1; ++r2) {
                int a1 = area(0, 0, r1, n - 1);
                int a2 = area(r1 + 1, 0, r2, n - 1);
                int a3 = area(r2 + 1, 0, m - 1, n - 1);
                if (a1 && a2 && a3) ans = min(ans, a1 + a2 + a3);
            }
        }

        // Try 3 vertical stripes
        for (int c1 = 0; c1 < n - 2; ++c1) {
            for (int c2 = c1 + 1; c2 < n - 1; ++c2) {
                int a1 = area(0, 0, m - 1, c1);
                int a2 = area(0, c1 + 1, m - 1, c2);
                int a3 = area(0, c2 + 1, m - 1, n - 1);
                if (a1 && a2 && a3) ans = min(ans, a1 + a2 + a3);
            }
        }

        // Try horizontal cut, then vertical cut in top part
        for (int r = 0; r < m - 1; ++r) {
            for (int c = 0; c < n - 1; ++c) {
                int a1 = area(0, 0, r, c);
                int a2 = area(0, c + 1, r, n - 1);
                int a3 = area(r + 1, 0, m - 1, n - 1);
                if (a1 && a2 && a3) ans = min(ans, a1 + a2 + a3);
            }
        }

        // Try horizontal cut, then vertical cut in bottom part
        for (int r = 0; r < m - 1; ++r) {
            for (int c = 0; c < n - 1; ++c) {
                int a1 = area(0, 0, r, n - 1);
                int a2 = area(r + 1, 0, m - 1, c);
                int a3 = area(r + 1, c + 1, m - 1, n - 1);
                if (a1 && a2 && a3) ans = min(ans, a1 + a2 + a3);
            }
        }

        // Try vertical cut, then horizontal cut in left part
        for (int c = 0; c < n - 1; ++c) {
            for (int r = 0; r < m - 1; ++r) {
                int a1 = area(0, 0, r, c);
                int a2 = area(r + 1, 0, m - 1, c);
                int a3 = area(0, c + 1, m - 1, n - 1);
                if (a1 && a2 && a3) ans = min(ans, a1 + a2 + a3);
            }
        }

        // Try vertical cut, then horizontal cut in right part
        for (int c = 0; c < n - 1; ++c) {
            for (int r = 0; r < m - 1; ++r) {
                int a1 = area(0, 0, m - 1, c);
                int a2 = area(0, c + 1, r, n - 1);
                int a3 = area(r + 1, c + 1, m - 1, n - 1);
                if (a1 && a2 && a3) ans = min(ans, a1 + a2 + a3);
            }
        }

        return ans;
    }
};