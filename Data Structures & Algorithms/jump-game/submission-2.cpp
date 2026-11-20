class Solution {
public:
    bool find(vector<int>& nums,int i,int n,vector<int>&dp){
        if(i>=n)return false;
        if(i == n-1)return true;
        if(dp[i] != -1)return dp[i];
        bool jump;
        for(int k=1;k<=nums[i];k++){
            jump = find(nums,i+k,n,dp);
            if(jump == true)return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        bool ans = find(nums,0,n,dp);
        return ans;
    }
};
