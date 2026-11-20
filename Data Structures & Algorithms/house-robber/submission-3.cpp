class Solution {
public:
    int solve(int i,int n,vector<int>nums,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i] != -1)return dp[i];
        // take
        int take = 0;
        take = nums[i] + solve(i+2,n,nums,dp);
        int skip = 0;
        skip = solve(i+1,n,nums,dp);

        return dp[i] = max(skip,take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int ans = solve(0,n,nums,dp);
        return ans;
    }
};
