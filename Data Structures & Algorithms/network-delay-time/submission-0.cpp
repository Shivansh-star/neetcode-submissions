class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Fix 1: Use a vector of pairs to store multiple edges for a single node
        unordered_map<int, vector<pair<int,int>>> adj;
        
        for(int i = 0; i < times.size(); i++){
            int src = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            adj[src].push_back({dest, time});
        }
        
        // pq stores {time_to_reach_node, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Fix 2: 1-based indexing, so size is n + 1
        vector<bool> vis(n + 1, false);
        
        pq.push({0, k});
        int maxi = 0;
        int visitedCount = 0; // Track how many nodes we successfully reach
        
        while(!pq.empty()){
            auto [currentTime, currentNode] = pq.top();
            pq.pop();
            
            // Fix 6: If we've already processed this node via a faster path, skip it
            if(vis[currentNode]) continue;
            
            vis[currentNode] = true;
            visitedCount++;
            maxi = max(maxi, currentTime);
            
            // Fix 3: Rename `n` to `neighbor` to avoid shadowing
            for(auto &neighbor : adj[currentNode]){
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;
                
                // Fix 4: Only push if NOT visited, and push {total_time, next_node}
                if(!vis[nextNode]){
                    pq.push({currentTime + travelTime, nextNode});
                }
            }
        }
        
        // Fix 5: If we didn't visit all n nodes, return -1. Otherwise return maxi.
        return visitedCount == n ? maxi : -1;
    }
};