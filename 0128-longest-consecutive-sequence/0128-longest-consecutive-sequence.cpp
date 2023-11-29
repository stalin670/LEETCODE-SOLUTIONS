class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(size(nums)==0) return 0;
        sort(nums.begin(),nums.end());
        int ans=1,curr=1;
        for(int i=1;i<size(nums);i++){
            if(nums[i]==nums[i-1]+1){
                curr++;
            }
            if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]!=nums[i-1]+1){
                curr=1;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};