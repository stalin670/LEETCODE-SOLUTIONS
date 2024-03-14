class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int cur = 0, ans = 0;
        mp[0]++;
        for(auto it: nums)
        {
            cur += it;
            ans += mp[cur - goal];
            mp[cur]++;
        }
        return ans;
    }
};