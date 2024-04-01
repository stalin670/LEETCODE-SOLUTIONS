#define ll long long
class Solution {
public:
    ll memo(ll i, ll j, string & a, string & b, vector<vector<ll>> & dp) {
        if(i == 0 || j == 0)
            return 0LL;
        if(dp[i][j] != -1LL)
            return dp[i][j];
        
        if(a[i - 1] == b[j - 1]) 
            return dp[i][j] = 1LL + memo(i - 1, j - 1, a, b, dp);
        
        return dp[i][j] = max(memo(i - 1, j, a, b, dp), memo(i, j - 1, a, b, dp));
    }
    string shortestCommonSupersequence(string a, string b) {
        ll n = a.size();
        ll m = b.size();
        
        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, -1LL));
        
        ll maxi = memo(n, m, a, b, dp);
        
        string ans = "";
        
        ll i = n, j = m;
        
        while(i > 0 and j > 0) {
            if(a[i - 1] == b[j - 1]) {
                ans += a[i - 1];
                i--, j--;
            }
            else {
                if(dp[i - 1][j] > dp[i][j - 1]) {
                    ans += a[i - 1];
                    i--;
                }
                else {
                    ans += b[j - 1];
                    j--;
                }
            }
        }
        
        while(i > 0)
            ans += a[i - 1], i--;
        while(j > 0)
            ans += b[j - 1], j--;
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};