class Solution {
public:
    #define ll long long
    int firstMissingPositive(vector<int>& arr) {
        ll n = arr.size();
        bool have_one = false;
        for(ll i = 0; i < n; i++) {
            if(arr[i] == 1) {
                have_one = true;
            }
            if(arr[i] <= 0 || arr[i] > n) {
                arr[i] = 1;
            }
        }
        
        if(!have_one)
            return 1;
        
        for(ll i = 0; i < n; i++) {
            ll val = abs(arr[i]);
            if(arr[val - 1] > 0) {
                arr[val - 1] = -arr[val - 1];
            }
        }
        for(ll i = 0; i < n; i++) {
            if(arr[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};