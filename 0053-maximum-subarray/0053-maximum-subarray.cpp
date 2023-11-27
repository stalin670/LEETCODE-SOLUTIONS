class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int currMax=0;
        for(int i=0;i<nums.size();i++){
            currMax+=nums[i];
            if(ans<currMax) ans=currMax;
            if(currMax<0) currMax=0;
        }
        return ans;
    }
};