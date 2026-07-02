class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        deque<pair<int,int>> dq;

        dis[0][0] = grid[0][0];
        dq.push_front({0,0});

        vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        while(!dq.empty()){

            auto [r,c] = dq.front();
            dq.pop_front();

            for(auto d:dir){

                int nr = r + d.first;
                int nc = c + d.second;

                if(nr<0 || nc<0 || nr>=n || nc>=m)
                    continue;

                int newCost = dis[r][c] + grid[nr][nc];

                if(newCost < dis[nr][nc]){

                    dis[nr][nc] = newCost;

                    if(grid[nr][nc]==0)
                        dq.push_front({nr,nc});
                    else
                        dq.push_back({nr,nc});
                }
            }
        }

        return dis[n-1][m-1] <= health-1;
    }
};