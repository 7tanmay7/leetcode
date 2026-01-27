class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph[u].push_back(make_pair(v, w));
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // min-heap: pair<distance, node>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, k));

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currDist > dist[u]) continue;

            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].first;
                int w = graph[u][i].second;
                if (dist[v] > currDist + w) {
                    dist[v] = currDist + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            result = max(result, dist[i]);
        }
        return result;
    }
};