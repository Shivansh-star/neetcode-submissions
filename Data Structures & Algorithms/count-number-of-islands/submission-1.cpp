class Solution {
public:
    int r[4] = {1,-1,0,0};
    int c[4] = {0,0,-1,1};

    void dfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<bool>>& vis, int row, int col) {

        if(i >= row || j >= col || i < 0 || j < 0 ||
           vis[i][j] || grid[i][j] == '0') {
            return;
        }

        vis[i][j] = true;

        for(int k = 0; k < 4; k++) {
            int new_r = i + r[k];
            int new_c = j + c[k];

            dfs(grid, new_r, new_c, vis, row, col);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        int cnt = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {

                if(grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(grid, i, j, vis, row, col);
                }
            }
        }

        return cnt;
    }
};