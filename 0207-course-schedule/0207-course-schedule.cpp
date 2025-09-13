
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);   // adjacency list
        vector<int> inDeg(numCourses, 0);      // in-degree array

        // Build the graph and in-degree array
        for (int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0]; // course to take
            int u = prerequisites[i][1]; // prerequisite
            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        // Push all courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) q.push(i);
        }

        int count = 0; // Number of courses we can finish

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                inDeg[neighbor]--;
                if (inDeg[neighbor] == 0) q.push(neighbor);
            }
        }

        // If we finished all courses, it's possible
        return count == numCourses;
    }
};
