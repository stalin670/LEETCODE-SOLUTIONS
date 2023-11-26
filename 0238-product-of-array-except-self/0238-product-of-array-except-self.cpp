class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1,zeroes=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) product*=nums[i];
            else zeroes++;
        }
        vector<int> ans(nums.size(),0);
        if(zeroes>1) return ans;
        if(zeroes==1){  
            for(int i=0;i<nums.size();i++) if(nums[i]==0) ans[i]=product;
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=product/nums[i];
        }
        return ans;
    }
};