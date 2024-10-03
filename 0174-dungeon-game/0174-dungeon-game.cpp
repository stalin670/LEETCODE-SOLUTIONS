class Solution {
public:
    #define ll long long
    int calculateMinimumHP(vector<vector<int>>& arr) {
        ll n = arr.size(), m = arr[0].size();
        vector<vector<ll>> dp(n, vector<ll>(m));
        for(ll i = n - 1; i >= 0; i--) {
            for(ll j = m - 1; j >= 0; j--) {
                if(i == n - 1 and j == m - 1) {
                    dp[i][j] = min(0, arr[i][j]);
                }
                else if(i == n - 1) {
                    dp[i][j] = min(0LL, arr[i][j] + dp[i][j + 1]);
                }
                else if(j == m - 1) {
                    dp[i][j] = min(0LL, arr[i][j] + dp[i + 1][j]);
                }
                else {
                    dp[i][j] = min(0LL, arr[i][j] + max(dp[i][j + 1], dp[i + 1][j]));
                }
            }
        }
        return abs(dp[0][0]) + 1;
    }
};