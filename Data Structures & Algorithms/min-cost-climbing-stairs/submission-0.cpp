class Solution {
public:
    int solve(vector<int>& cost, int n, int i, vector<int>& dp){
        if(i >= n) return 0; 
        
        if(dp[i] != -1) return dp[i]; 

        int one = 0;
        one = one + cost[i] + solve(cost, n, i + 1, dp);
        
        int two = 0;
        two = two + cost[i] + solve(cost, n, i + 2, dp); 
        return dp[i] = min(one, two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n + 1, -1); 
        
        // start at 0
        int ans = solve(cost, n, 0, dp);
        // start at 1
        int val = solve(cost, n, 1, dp);

        return min(ans, val);
    }
};