class Solution {
public:
    #define ll long long
    ll mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll> arr;
        for(ll i = 0; i < n; i++) {
            ll range_sum = 0;
            for(ll j = i; j < n; j++) {
                range_sum += nums[j];
                arr.push_back(range_sum);
                // cout << range_sum << " ";
            }
        }
        sort(arr.begin(), arr.end());
        ll range_sum = 0;
        left--;
        right--;
        for(ll i = left; i <= right; i++) {
            range_sum += arr[i];
            range_sum %= mod;
            // cout << arr[i] << " ";
        }
        // cout << endl;
        return range_sum;
    }
};