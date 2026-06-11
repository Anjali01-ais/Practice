class Solution {
public:
     const int MOD = 1e9 + 7;

    long long modExp(long long base, long long exp) {
        long long res = 1;
        while (exp) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
       int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // BFS to find max depth
        queue<pair<int,int>> q;
        vector<bool> vis(n + 1, false);

        q.push({1, 0});
        vis[1] = true;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = true;
                    q.push({nei, depth + 1});
                }
            }
        }

        // answer = 2^(d-1)
        return modExp(2, maxDepth - 1); 
    }
};