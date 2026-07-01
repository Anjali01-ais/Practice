class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                   q.push({i,j});
                   dis[i][j]=0;
                }
            }
        }
         vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
         while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int nr=x+dir[k].first;
                int nc=y+dir[k].second;
                if(nc>=0&& nr>=0&&nc<m&& nr<n&&dis[nr][nc]==-1){
                    dis[nr][nc]=dis[x][y]+1;
                    q.push({nr,nc});
                }
            }
         }
       return dis;
    }
};