class Solution {
public:
    long long f(int i,int j,int maxi,vector<vector<long long>>&dp,const int mod){
        if(i==0){
            if(j==0) return 1;
            return 0;
        }
        if(i<0 || j<0 || j>=maxi) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        long long ways=f(i-1,j,maxi,dp,mod)%mod;
        ways+=f(i-1,j-1,maxi,dp,mod)%mod;
        ways+=f(i-1,j+1,maxi,dp,mod)%mod;

        dp[i][j]=ways%mod;
        return ways%mod;
    }
    int numWays(int steps, int arrLen) {
        const int mod=1e9+7;
        vector<vector<long long>> dp(steps+1,vector<long long>(steps+1,-1));
        return f(steps,0,arrLen,dp,mod);
    }
};