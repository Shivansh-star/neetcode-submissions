class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node){
        vis[node] = true;
        for(auto &i: adj[node]){
            if(vis[i] == false){
                dfs(adj,vis,i);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        //int n = edges.size();
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);
        int cnt = 0;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i] == false){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};
