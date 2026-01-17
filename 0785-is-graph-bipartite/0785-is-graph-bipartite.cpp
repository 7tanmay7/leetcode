class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored

        for (int start = 0; start < n; ++start) {
            if (color[start] != -1) continue; // Already visited

            queue<int> q;
            q.push(start);
            color[start] = 0; // Start coloring with 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node]; // Alternate color
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // Conflict in coloring
                    }
                }
            }
        }

        return true; // No conflicts → bipartite
    }
};