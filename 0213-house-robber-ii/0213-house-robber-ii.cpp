class Solution {
public:
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
        if(size(nums)==1) return nums[0];
        vector<int> a,b;
        for(int i=0;i<size(nums);i++){
            if(i!=0) b.push_back(nums[i]);
            if(i!=size(nums)-1) a.push_back(nums[i]);
        }
        vector<int> dp1(size(a)+1,-1),dp2(size(b)+1,-1);
        int ans1=f(size(a)-1,a,dp1);
        int ans2=f(size(b)-1,b,dp2);
        return max(ans1,ans2);
    }
};