class Solution {
public:
    int f(int ind,int target,vector<int> coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target%coins[0]==0) return target/coins[0];
            else return 1e9;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int notPick=0+f(ind-1,target,coins,dp);
        int pick=1e9;
        if(coins[ind]<=target){
            pick=1+f(ind,target-coins[ind],coins,dp);
        }
        return dp[ind][target]=min(pick,notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(size(coins),vector<int>(amount+1,-1));
        int ans=f(size(coins)-1,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};