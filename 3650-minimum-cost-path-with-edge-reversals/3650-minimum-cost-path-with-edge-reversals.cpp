#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n), radj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            radj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            long long cost = cur.first;
            int u = cur.second;

            if (cost > dist[u]) continue;
            if (u == n - 1) return cost;

            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;
                if (cost + w < dist[v]) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }

            for (auto &p : radj[u]) {
                int v = p.first, w = p.second;
                long long nc = cost + 2LL * w;
                if (nc < dist[v]) {
                    dist[v] = nc;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};

