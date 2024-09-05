class Solution {
public:
    #define ll long long
    #define inf 1000000000
    ll helper_function(ll ind, ll n, vector<int>& arr, vector<ll>& dp) {
        if(ind >= n)
            return inf;
        if(ind == n - 1)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        ll maxi = inf;
        for(ll j = 1; j <= arr[ind]; j++) {
            maxi = min(maxi, 1 + helper_function(ind + j, n, arr, dp));
        }
        
        return dp[ind] = maxi;
    }
    int jump(vector<int>& arr) {
        ll n = arr.size();
        vector<ll> dp(n + 1, -1);
        return helper_function(0, n, arr, dp);
    }
};