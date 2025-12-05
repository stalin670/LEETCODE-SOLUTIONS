class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, nums[0]);
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        int ans = 0, suff = 0;
        for(int i = n - 1; i > 0; i--) {
            suff += nums[i];
            int diff = abs(suff - pref[i - 1]);
            if(diff % 2 == 0) ans++;
        }
        return ans;
    }
};