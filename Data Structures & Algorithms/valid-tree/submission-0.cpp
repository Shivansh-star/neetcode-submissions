
class Solution {
public:
    bool dfs(int i, unordered_map<int,vector<int>>& adj,
             vector<int>& parent, vector<bool>& visit) {

        for(auto &node : adj[i]) {

            if(visit[node] == true && parent[i] != node)
                return false;

            if(visit[node] == false) {
                visit[node] = true;
                parent[node] = i;

                if(!dfs(node, adj, parent, visit))
                    return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if(n-1 != edges.size()) return false;

        unordered_map<int,vector<int>> adj;

        for(int i=0; i<edges.size(); i++) {
            int first = edges[i][0];
            int second = edges[i][1];

            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        vector<int> parent(n,-1);
        vector<bool> visit(n,false);

        visit[0] = true;

        if(!dfs(0,adj,parent,visit))
            return false;

        for(int i=0; i<n; i++) {
            if(!visit[i]) return false;
        }

        return true;
    }
};
