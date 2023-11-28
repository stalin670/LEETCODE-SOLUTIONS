class Solution {
public:
    int len(vector<int> arr){
        return arr.size();
    }
    int f(int ind,vector<int>arr,vector<int>&dp){
        if(ind==0) return arr[ind];
        if(ind<0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        // include 
        int take=arr[ind] + f(ind-2,arr,dp);
            
        // not include
        int notTake = 0+f(ind-1,arr,dp);
        
        return dp[ind]=max(take,notTake);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(len(nums)+1,-1);
        return f(len(nums)-1,nums,dp);
    }
};