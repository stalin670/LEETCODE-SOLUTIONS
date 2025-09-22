#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll maxi = *max_element(nums.begin(), nums.end());
        ll mini = *min_element(nums.begin(), nums.end());
        ll diff = maxi - mini;
        return diff * k;
    }
};