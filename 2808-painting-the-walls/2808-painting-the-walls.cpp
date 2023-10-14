class Solution {
public:
    int dynamic(int i,int j,vector<int>& cost,vector<int>& time,vector<vector<int>>& dp) {    
        if(j<=0) return 0;
        if(i>=cost.size()) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        int include=cost[i]+dynamic(i+1,j-time[i]-1,cost,time,dp);
        int exclude=0+dynamic(i+1,j,cost,time,dp);

        return dp[i][j]=min(include,exclude);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(600,vector<int>(600,-1));
        return dynamic(0,n,cost,time,dp);
    }
};