class Solution {
public:
     void dfs(int u, vector<vector<int>>& adj, vector<int>& comp, vector<bool>& vis) {
        vis[u] = true;
        comp.push_back(u);

        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, comp, vis);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
             vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, comp, vis);

                int k = comp.size();
                bool ok = true;

                for (int node : comp) {
                    if (adj[node].size() != k - 1) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    ans++;
            }
        }

        return ans;   
    }
};