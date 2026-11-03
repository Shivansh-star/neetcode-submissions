class Solution {
public:
    int solve(int i,vector<int>& prices,int n,bool buy){
        if(i>=n)return 0;
        int ans = 0;
        int profit = 0;
        // abhi ni liya hai
        if(buy == 0){
            profit = max((-prices[i]+solve(i+1,prices,n,!buy)),solve(i+1,prices,n,buy));
        }else{
            profit = max((prices[i]),solve(i+1,prices,n,buy));
        }
        return ans = max(ans,profit);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = solve(0,prices,n,0);
        return ans;
    }
};
