class Solution {
public:
    #define ll long long
    long long findMaximumScore(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        ll lastInd = 0;
        for(ll i = 1; i < n; i++) {
            if(nums[i] > nums[lastInd]) {
                ans += (i - lastInd) * nums[lastInd];
                lastInd = i;
            }
        }
        if(lastInd != n - 1) {
            ans += (n - 1 - lastInd) * nums[lastInd];
        }
        return ans;
    }
};