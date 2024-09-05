class Solution {
public:
    #define ll long long
    bool helper_function(ll i, ll j, string &s, string &t, vector<vector<ll>>& dp) {
        if(i < 0 and j < 0)
            return true;
        if(j < 0)
            return false;
        if(i < 0) {
            bool found = true;
            while(j >= 0) {
                if(t[j] != '*') {
                    found = false;
                    break;
                }
                j--;
            }
            if(found)
                return true;
            else
                return false;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
         
        if (s[i] == t[j] || t[j] == '?') {
            return dp[i][j] = helper_function(i - 1, j - 1, s, t, dp);
        }
        if (t[j] == '*') {
            return dp[i][j] = helper_function(i - 1, j, s, t, dp) || helper_function(i, j - 1, s, t, dp);
        }
        return dp[i][j] = 0;
        
    }
    bool isMatch(string s, string t) {
        ll n = s.size(), m = t.size();
        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, -1));
        ll ans = helper_function(n - 1, m - 1, s, t, dp);
        if(ans == 0)
            return false;
        return true;
    }
};