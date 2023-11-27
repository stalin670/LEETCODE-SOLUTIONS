class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr=0;
        for(int i=0;i<size(nums);i++) xr^=nums[i];
        for(int i=0;i<=size(nums);i++) xr^=i;
        return xr;
    }
};