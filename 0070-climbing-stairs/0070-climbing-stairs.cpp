class Solution {
public:
    int f(int n,vector<int>& dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    
    int climbStairs(int n) {
        // int x=1,y=1;
        // for(int i=2;i<=n;i++){
        //     int curr=x+y;
        //     y=x;
        //     x=curr;
        // }
        // return x;
        
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};