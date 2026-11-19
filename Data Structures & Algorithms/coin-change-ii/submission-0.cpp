class Solution {
public:
    int solve(int amt,int i, vector<int>& coins, vector<vector<int>>& dp){
        if(amt == 0)return 1;
        if(i >= coins.size())return 0;

        if(dp[amt][i] != -1)return dp[amt][i];

        int take = 0;
        if(amt >= coins[i]){
            take = solve(amt-coins[i],i,coins,dp);
        }

        int skip = 0;
        skip = solve(amt,i+1,coins,dp);

        return dp[amt][i] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(amount+1,vector<int>(n,-1));

        int ans = solve(amount,0,coins,dp);
        return ans;
    }
};