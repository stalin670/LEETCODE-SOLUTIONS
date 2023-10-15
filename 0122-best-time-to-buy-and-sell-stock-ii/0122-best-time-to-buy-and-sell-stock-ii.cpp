class Solution {
public:
    int f(int i,int buy,vector<int>&arr,int n,vector<vector<int>>& dp){
        if(i==n) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy){
            profit=max(-arr[i]+f(i+1,0,arr,n,dp),0+f(i+1,1,arr,n,dp));
        }
        else{
            profit=max(arr[i]+f(i+1,1,arr,n,dp),0+f(i+1,0,arr,n,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,dp);
    }
};