class Solution {
public:
    int f(int i,int n,vector<int> arr,vector<int>&dp){
        if(i==0) return arr[0];
        if(i==1) return arr[1];
        if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i];

        int first=f(i-1,n,arr,dp)+arr[i];
        int sec=INT_MAX;
        if(i>1) sec=f(i-2,n,arr,dp)+arr[i];

        dp[i]=min(first,sec);

        return dp[i];

    }
    int minCostClimbingStairs(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        int x=f(n-1,n,arr,dp);
        vector<int> dp1(n,-1);
        int y=f(n-2,n,arr,dp1);
        return min(x,y);
    }
};