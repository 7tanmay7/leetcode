class Solution {
public:
void dfs(int node, vector<int> adj[], vector<bool>& vis){
    vis[node] = true;
    for(auto v : adj[node]){
        if(!vis[v])
            dfs(v, adj, vis);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int ans = 0, n = isConnected.size();
    vector<int> adj[n];
    
    // Convert isConnected matrix into adjacency list
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isConnected[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
    
    vector<bool> vis(n, false);
    
    // Perform DFS to find the number of provinces
    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans++;
            dfs(i, adj, vis);
        }
    }

    return ans;
}
};