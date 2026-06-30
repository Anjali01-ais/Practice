class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

       vector<int>topOrder;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topOrder.push_back(node);

            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
         if (topOrder.size() == numCourses)
    return topOrder;

return {};
    }
};