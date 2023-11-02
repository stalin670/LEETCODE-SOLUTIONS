class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> dp(n,0);
        dp[2]=max(0,k-max({nums[0],nums[1],nums[2]}));
        for(int i=3;i<n;i++){
            dp[i]=min({dp[i-1]+max(0,k-nums[i]),dp[i-2]+max(0,k-nums[i-1]),dp[i-3]+max(0,k-nums[i-2])});
        }
        return dp.back();
    }
};