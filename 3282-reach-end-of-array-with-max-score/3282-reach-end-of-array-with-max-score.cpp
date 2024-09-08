class Solution {
public:
    #define ll long long
    long long findMaximumScore(vector<int>& nums) {
        vector<pair<ll, ll>> arr;
        arr.push_back({0, nums[0]});
        ll ind = 0;
        for(ll i = 1; i < nums.size(); i++) {
            if(nums[i] > arr[ind].second) {
                arr.push_back({i, nums[i]});
                ind++;
            }
        }
        if(arr.back().first != nums.size() - 1) {
            arr.push_back({nums.size() - 1, nums[nums.size() - 1]});
        }
        
        ll ans = 0;
        for(ll i = 1; i < arr.size(); i++) {
            ans += (arr[i].first - arr[i - 1].first) * arr[i - 1].second;
        }
        
        return ans;
    }
};