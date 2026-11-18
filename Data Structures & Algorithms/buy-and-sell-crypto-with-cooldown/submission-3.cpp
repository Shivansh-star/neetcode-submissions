class Solution {
public:
    int solve(int i,int n,vector<int>& prices, int b, vector<vector<int>>& dp){
        if(i >= n)return 0;

        if(dp[i][b] != -1)return dp[i][b];

        int buy = 0;
        int sell = 0;
        int skip = 0;

        if(b == 0){
            buy = -prices[i] + solve(i+1,n,prices,1,dp);
            skip = solve(i+1,n,prices,0,dp);
        }
        else{
            sell = prices[i] + solve(i+2,n,prices,0,dp);
            skip = solve(i+1,n,prices,1,dp);
        }

        return dp[i][b] = max({buy,sell,skip});
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        int ans = solve(0,n,prices,0,dp);
        return ans;
    }
};