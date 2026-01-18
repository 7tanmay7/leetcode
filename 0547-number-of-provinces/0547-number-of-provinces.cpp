class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1;

        for (int i = 0; i < (int)adj[node].size(); i++) {
            int neigh = adj[node][i];
            if (visited[neigh] == 0) {
                dfs(neigh, adj, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                cnt++;
                dfs(i, adj, visited);
            }
        }

        return cnt;
    }
};
