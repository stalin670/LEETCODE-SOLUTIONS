#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& arr, int p) {
        ll n = arr.size();
        ll total_sum = 0;
        for(ll i = 0; i < n; i++)
            total_sum += arr[i];
        
        // check if array is already divisible by P
        if(total_sum % p == 0) {
            // No need to remove anything
            return 0;
        }
        
        map<ll, ll> mp; // Storing the remainders
        mp[0] = -1;
        ll pref_sum = 0, min_len = 1e9;
        
        for(ll i = 0; i < n; i++) {
            // sum up the values as prefix sum
            pref_sum += arr[i];
            // finding the remainder required
            ll req_remainder = (pref_sum % p - (total_sum % p) + p) % p;
            
            // check in map, if it is already occured or not
            if(mp.find(req_remainder) != mp.end()) {
                min_len = min(min_len, i - mp[req_remainder]);
            }
            mp[pref_sum % p] = i;
        }
        // if the min_len not changes than it's impossible
        if(min_len >= n)
            return -1;
        return min_len;
    }
};