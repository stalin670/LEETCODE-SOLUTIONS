class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<size(nums);i++){
            for(int j=i+1;j<size(nums);j++){
                ans=max(ans,(nums[i]-1)*(nums[j]-1));
            }
        }
        return ans;
    }
};