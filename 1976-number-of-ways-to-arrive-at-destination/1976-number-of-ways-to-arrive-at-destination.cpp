class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1000000007;
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // min-heap: pair<distance, node>
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push(make_pair(0, 0));

        while (!pq.empty()) {
            pair<long long, int> curr = pq.top();
            pq.pop();
            long long currDist = curr.first;
            int u = curr.second;

            if (currDist > dist[u]) continue;

            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].first;
                int w = graph[u][i].second;
                if (dist[v] > currDist + w) {
                    dist[v] = currDist + w;
                    ways[v] = ways[u];
                    pq.push(make_pair(dist[v], v));
                } else if (dist[v] == currDist + w) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};