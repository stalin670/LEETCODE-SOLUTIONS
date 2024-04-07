#define ll long long
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        ll ans = 1;
        ll n = arr.size();
        for(ll i = 0; i < n; i++) {
            ll len1 = 1, len2 = 1;
            for(ll j = i; j < n - 1; j++) {
                if(arr[j] < arr[j + 1])
                    len1++;
                else
                    break;
            }
            for(ll j = i; j < n - 1; j++) {
                if(arr[j] > arr[j + 1])
                    len2++;
                else
                    break;
            }
            ans = max(ans, max(len1, len2));
        }
        return ans;
    }
};