class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        if(j >= t.length()) return 1;
        if(i >= s.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;
        int skip = 0;

        if(s[i] == t[j]){
            take = solve(s,t,i+1,j+1,dp);
        }

        skip = solve(s,t,i+1,j,dp);

        return dp[i][j] = skip + take;
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int>(m,-1));

        return solve(s,t,0,0,dp);
    }
};