class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, 1e9);
        cost[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> temp = cost;
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if (cost[u] != 1e9 && cost[u] + w < temp[v]) {
                    temp[v] = cost[u] + w;
                }
            }
            cost = temp;
        }
        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};