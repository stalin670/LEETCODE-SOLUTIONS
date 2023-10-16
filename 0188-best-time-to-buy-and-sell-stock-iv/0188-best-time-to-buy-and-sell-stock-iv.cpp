class Solution {
public:
    int f(int i,int buy,int limit,vector<int>&arr,int n,vector<vector<vector<int>>> & dp) {
        if(limit==0) return 0;
        if(i==n) return 0;

        if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];

        int profit=0;
        if(buy){
            profit=max(-arr[i]+f(i+1,0,limit,arr,n,dp),0+f(i+1,1,limit,arr,n,dp));
        }
        else{
            profit=max(arr[i]+f(i+1,1,limit-1,arr,n,dp),0+f(i+1,0,limit,arr,n,dp));
        }
        return dp[i][buy][limit]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,prices,n,dp);
    }
};