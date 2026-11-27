
class Solution {
public:
    int solve(string &w1,string &w2,int n1,int n2,int i,int j,vector<vector<int>>&dp){
        if(i >= n1) return n2-j;
        if(j >= n2) return n1-i;

        if(dp[i][j] != -1) return dp[i][j];

        int rep = 0;
        int del = 0;
        int ins = 0;

        if(w1[i] == w2[j]){
            return dp[i][j] = solve(w1,w2,n1,n2,i+1,j+1,dp);
        }else{
            ins = 1+solve(w1,w2,n1,n2,i,j+1,dp);
            del = 1+solve(w1,w2,n1,n2,i+1,j,dp);
            rep = 1+solve(w1,w2,n1,n2,i+1,j+1,dp);
        }

        return dp[i][j] = min(ins,min(del,rep));
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(n1,vector<int>(n2,-1));

        return solve(word1,word2,n1,n2,0,0,dp);
    }
};
