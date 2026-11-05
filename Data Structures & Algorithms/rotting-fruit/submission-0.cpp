class Solution {
public:
    int r[4] = {1,-1,0,0};
    int c[4] = {0,0,-1,1};

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        queue<tuple<int,int,int>> q;

        // Push all initially rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {

            auto [x,y,z] = q.front();
            q.pop();

            ans = max(ans,z);

            for(int k = 0; k < 4; k++) {

                int new_r = x + r[k];
                int new_c = y + c[k];

                if(new_r >= 0 && new_r < n &&
                   new_c >= 0 && new_c < m &&
                   grid[new_r][new_c] == 1) {

                    grid[new_r][new_c] = 2;

                    q.push({new_r,new_c,z+1});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};