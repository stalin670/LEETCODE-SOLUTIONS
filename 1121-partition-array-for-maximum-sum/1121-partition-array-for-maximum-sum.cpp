class Solution {
public:
    int f(int i,int k,int n,vector<int>&arr,vector<int>&dp){
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        int len=0,maxi=INT_MIN,maxAns=INT_MIN;
        
        for(int j=i;j<min(i+k,n);j++){

            len++;
            maxi=max(maxi,arr[j]);
            int currMaxSum=len*maxi + f(j+1,k,n,arr,dp);

            maxAns=max(maxAns,currMaxSum);
        }

        return dp[i]=maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return f(0,k,n,arr,dp);
    }
};