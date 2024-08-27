class Solution {
public:
    #define ll long long
    ll helper_function(ll ind, ll m, ll n, vector<int>& arr, vector<vector<ll>>& dp) {
        if(ind >= n)
            return 0;
        
        if(dp[ind][m] != -1)
            return dp[ind][m];
        
        ll alice_total = 0;
        ll ans = -1e9;
        for(ll i = 0; i < 2 * m; i++) {
            if(ind + i < n) 
                alice_total += arr[i + ind];
            ans = max(ans, alice_total - helper_function(i + ind + 1, max(m, i + 1), n, arr, dp));
        }
        return dp[ind][m] = ans;
    }
    ll stoneGameII(vector<int>& arr) {
        vector<vector<ll>> dp(arr.size() + 1, vector<ll> (2 * arr.size() + 1, -1));
        ll sum = accumulate(arr.begin(), arr.end(), 0);
        ll diff = helper_function(0, 1, arr.size(), arr, dp);
        return (sum + diff) / 2;
    }
};