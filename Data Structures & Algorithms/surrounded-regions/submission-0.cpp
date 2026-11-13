
class Solution {
public:
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    void dfs(vector<vector<char>>& board,int i,int j,int r,int c){

        board[i][j] = 'Z';

        for(int k=0;k<4;k++){
            int new_r = dr[k]+i;
            int new_c = dc[k]+j;

            if(new_r>=0 && new_r<r && new_c>=0 && new_c<c && board[new_r][new_c] == 'O'){
                dfs(board,new_r,new_c,r,c);
            }
        }
        return;
    }

    void solve(vector<vector<char>>& board) {

        if(board.empty() || board[0].empty()) return;

        int row = board.size();
        int col = board[0].size();

        // top row
        for(int i=0;i<col;i++){
            if(board[0][i] == 'O'){
                dfs(board,0,i,row,col);
            }
        }

        // left col
        for(int i=0;i<row;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0,row,col);
            }
        }

        // right col
        for(int i=0;i<row;i++){
            if(board[i][col-1] == 'O'){
                dfs(board,i,col-1,row,col);
            }
        }

        // bottom row
        for(int i=0;i<col;i++){
            if(board[row-1][i] == 'O'){
                dfs(board,row-1,i,row,col);
            }
        }

        // replace
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'Z'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
