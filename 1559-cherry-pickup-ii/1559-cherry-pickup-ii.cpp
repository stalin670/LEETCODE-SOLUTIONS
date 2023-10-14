class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        // Base condition
        if(i>=grid.size() || j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;

        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        for(int k1=-1;k1<=1;k1++){
            for(int k2=-1;k2<=1;k2++){
                if(j1==j2){
                    ans=max(ans,grid[i][j1]+f(i+1,j1+k1,j2+k2,grid,dp));
                }
                else{
                    ans=max(ans,grid[i][j1]+grid[i][j2]+f(i+1,j1+k1,j2+k2,grid,dp));
                }
            }
        }
        dp[i][j1][j2]=ans;
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,dp);
    }
};