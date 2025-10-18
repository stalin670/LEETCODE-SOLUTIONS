#define ll long long
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        set<ll> st;
        ll lastVal = -1e18;
        sort(nums.begin(), nums.end());
        for(auto value : nums) {
            ll val = max((value - k) * 1LL, lastVal + 1);
            if(val <= value + k) {
                lastVal = val;
                st.insert(val);
            }
        }
        return st.size();
    }
};