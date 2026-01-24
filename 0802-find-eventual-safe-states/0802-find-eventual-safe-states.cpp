class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        // Build the reverse graph and indegree count
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        // Safe nodes start as terminal nodes (indegree 0 in reverse graph)
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<bool> safe(n, false);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            safe[node] = true;
            for (int prev : revGraph[node]) {
                indegree[prev]--;
                if (indegree[prev] == 0) q.push(prev);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) result.push_back(i);
        }
        return result;
    }
};