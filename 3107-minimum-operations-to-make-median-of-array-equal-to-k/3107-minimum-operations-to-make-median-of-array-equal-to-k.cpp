#define ll long long
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& arr, int k) {
        ll n = arr.size();
        ll ans = 0;
        sort(arr.begin(), arr.end());
        ll middle = n / 2;
        if(arr[middle] == k)
            return 0;
        if(arr[middle] > k) {
            for(ll i = middle; i >= 0; i--) {
                if(arr[i] > k)
                    ans += arr[i] - k;
                else 
                    break;
            }
        }
        else {
            for(ll i = middle; i < n; i++) {
                if(arr[i] < k)
                    ans += abs(arr[i] - k);
                else 
                    break;
            }
        }
        return ans;
    }
};