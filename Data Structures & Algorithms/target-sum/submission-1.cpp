class Solution {
public:
    int solve(vector<int>& nums, int t, int i, int sum,
              vector<vector<int>>& dp){

        if(i >= nums.size()){
            if(t == 0)return 1;
            return 0;
        }

        if(t + sum < 0 || t + sum > 2*sum)
            return 0;

        if(dp[i][t+sum] != -1)
            return dp[i][t+sum];

        int sub = solve(nums,t-nums[i],i+1,sum,dp);

        int add = solve(nums,t+nums[i],i+1,sum,dp);

        return dp[i][t+sum] = add+sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        if(abs(target) > sum)return 0;

        vector<vector<int>> dp(n,vector<int>(2*sum+1));

        for(auto &i : dp){
            fill(i.begin(),i.end(),-1);
        }

        int ans = solve(nums,target,0,sum,dp);
        return ans;
    }
};