class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // Create adjacency list
        vector<int> adj[n];
        vector<int> Indeg(n, 0);

        // Build the graph (0-based indexing)
        for (int i = 0; i < relations.size(); i++) {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
            Indeg[relations[i][1] - 1]++;
        }

        // Queue for Kahn's algorithm
        queue<int> q;
        // Maximum time to complete each course
        vector<int> CourseTime(n, 0);

        // Add courses with no prerequisites
        for (int i = 0; i < n; i++) {
            if (Indeg[i] == 0) {
                q.push(i);
                CourseTime[i] = time[i];
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                int next = adj[node][j];
                // Update the max time for the next course
                CourseTime[next] = max(CourseTime[next], CourseTime[node] + time[next]);
                Indeg[next]--;
                if (Indeg[next] == 0) {
                    q.push(next);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, CourseTime[i]);
        }

        return ans;
    }
};