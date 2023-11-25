class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> prefix(n),suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        for(int i=n-2;i>=0;i--) suffix[i]=suffix[i+1]+nums[i];
        
        for(int i=0;i<n;i++){
            int left=nums[i]*i - prefix[i];
            int right=suffix[i] - nums[i]*(n-i-1);
            ans[i]=left+right;
        }
        
        return ans;
    }
};