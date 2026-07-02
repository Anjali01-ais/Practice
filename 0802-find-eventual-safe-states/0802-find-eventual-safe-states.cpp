class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adjrev[n];
        vector<int>outdegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it:graph[i]){
                adjrev[it].push_back(i);
                outdegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<int>safeNode;
        while(!q.empty()){
           int node=q.front();
           q.pop();
           safeNode.push_back(node);
           for(auto it:adjrev[node]){
            outdegree[it]--;
            if(outdegree[it]==0){
                q.push(it);
            }
           }
        }
        sort(safeNode.begin(),safeNode.end());
        return safeNode;
    }
};