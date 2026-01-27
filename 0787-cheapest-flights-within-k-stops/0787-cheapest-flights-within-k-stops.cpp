class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            graph[u].push_back(make_pair(v, w));
        }
        
        vector<int> cost(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q; // {current city, {current cost, stops}}
        q.push(make_pair(src, make_pair(0, 0)));
        cost[src] = 0;
        
        while (!q.empty()) {
            int city = q.front().first;
            int currCost = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();
            
            if (stops > k) continue;
            
            for (int i = 0; i < graph[city].size(); i++) {
                int next = graph[city][i].first;
                int price = graph[city][i].second;
                if (currCost + price < cost[next]) {
                    cost[next] = currCost + price;
                    q.push(make_pair(next, make_pair(cost[next], stops + 1)));
                }
            }
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};