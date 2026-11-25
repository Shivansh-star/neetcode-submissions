class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool>vis(n,false);
        vector<int>dis(n,INT_MAX);

        int cost = 0;
        dis[0] = 0;

        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            int node = -1;

            for(int j=0;j<n;j++){
                if(vis[j])continue;

                if(dis[j] < mini){
                    mini = dis[j];
                    node = j;
                }
            }

            vis[node] = true;
            cost += mini;

            for(int j=0;j<n;j++){
                if(vis[j])continue;

                int dist = abs(points[node][0]-points[j][0])
                         + abs(points[node][1]-points[j][1]);

                dis[j] = min(dis[j],dist);
            }
        }

        return cost;
    }
};