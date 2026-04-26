class Solution {
public:
    void mark(int i, int j, vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int row = 0; row < n; row++){
            if(matrix[row][j] != 0)
                matrix[row][j] = INT_MIN;
        }
        
        for(int col = 0; col < m; col++){
            if(matrix[i][col] != 0)
                matrix[i][col] = INT_MIN;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    mark(i, j, matrix);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == INT_MIN){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};