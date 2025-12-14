class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); ++i) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n, -1);   // Time of insertion for each node
        vector<int> low(n, -1);   // Lowest time reachable from the node
        vector<bool> visited(n, false); // Visited array
        vector<vector<int>> bridges;    // Store critical connections
        int timer = 0;

        // DFS function with complete for loop and comments
        function<void(int, int)> dfs = [&](int node, int parent) {
            visited[node] = true;
            tin[node] = low[node] = timer++; // Set insertion and low time

            // Explore all adjacent nodes
            for (int i = 0; i < adj[node].size(); ++i) {
                int neighbor = adj[node][i];
                if (neighbor == parent) continue; // Skip the parent node

                if (!visited[neighbor]) {
                    dfs(neighbor, node); // Recursive DFS call
                    low[node] = min(low[node], low[neighbor]); // Update low time

                    // If the lowest time of neighbor is greater than insertion time of node, it's a bridge
                    if (low[neighbor] > tin[node]) {
                        bridges.push_back({node, neighbor});
                    }
                } else {
                    // Update low time if neighbor already visited (back edge)
                    low[node] = min(low[node], tin[neighbor]);
                }
            }
        };

        // Start DFS from node 0 (assuming the graph is connected)
        dfs(0, -1);

        return bridges; // Return all critical connections found
    }
};