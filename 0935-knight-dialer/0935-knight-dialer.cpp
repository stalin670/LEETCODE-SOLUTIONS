class Solution {
public:
    const int mod=int(1e9+7);
    vector<vector<int>> adj={
        {4,6},{6,8},{7,9},{4,8},{3,9,0},{},{0,1,7},{2,6},{1,3},{2,4}
    };
    int dp[5000][10];
    int f(int rem,int num) {
        //base case
        if(rem==0) return 1;
        if(dp[rem][num]!=-1) return dp[rem][num];

        int ans=0;
        for(auto j :adj[num]) {
            ans+=f(rem-1,j);
            ans%=mod;
        }
        return dp[rem][num]=ans;
    }
    
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int num=0;num<10;++num) {
            ans+=f(n-1,num);
            ans%=mod;
        }
        return ans;
    }
};