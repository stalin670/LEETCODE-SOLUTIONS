class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=target-nums[i];
            if(mp.find(x)!=mp.end()){
                return {i,mp[x]};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};