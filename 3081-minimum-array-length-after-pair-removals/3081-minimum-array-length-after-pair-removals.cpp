class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums) m[it]++;
        int ans=nums.size();
        int Max=0;
        for(auto it:m)Max=max(Max,it.second);
        ans=2*Max-nums.size();
        if(ans<0)return nums.size()&1;
        return ans;
        
    }
};