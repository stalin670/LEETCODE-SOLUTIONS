class Solution {
public:
    int f(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        if(i==arr.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int include=j*arr[i] + f(i+1,j+1,arr,dp);
        int exclude=0+f(i+1,j,arr,dp);

        return dp[i][j]=max(include,exclude);
    }

    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,1,arr,dp);
    }
};