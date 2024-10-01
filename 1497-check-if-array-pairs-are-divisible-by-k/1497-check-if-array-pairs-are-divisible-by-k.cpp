class Solution {
public:
    #define ll long long
    bool canArrange(vector<int>& arr, int k) {
        vector<ll> freq(k, 0);
        ll n = arr.size();
        for(ll i = 0; i < n; i++) {
            ll r = arr[i] % k;
            if(r < 0)
                r += k;
            freq[r]++;
        }
        if(freq[0] & 1) {
            return false;
        }
        for(ll i = 1; i <= k / 2; i++) {
            if(freq[i] != freq[k - i])
                return false;
        }
        return true;
    }
};