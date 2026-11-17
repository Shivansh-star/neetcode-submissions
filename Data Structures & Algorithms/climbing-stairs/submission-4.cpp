class Solution {
public:
    int dp[46];

    int check(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = check(n-1) + check(n-2);
    }

    int climbStairs(int n) {
        fill(dp, dp + 46, -1);
        return check(n);
    }
};