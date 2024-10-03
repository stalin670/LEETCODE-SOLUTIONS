class Solution {
public:
    #define ll long long
    unordered_map<string, bool> dp;
    bool helper_function(string s, string t) {
        if(s.size() == 1)
            return s == t;
        if(s == t)
            return true;
        
        string key = s + t;
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        ll n = s.size();
        vector<ll> freqS(26, 0), freqT(26, 0);
        for(ll i = 0; i < n; i++) {
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }
        if(freqS != freqT) {
            return dp[key] = false;
        }
        
        for(ll i = 1; i < n; i++) {
            if((helper_function(s.substr(0, i), t.substr(0, i)) and helper_function(s.substr(i), t.substr(i))) || 
               (helper_function(s.substr(0, i), t.substr(n - i)) and helper_function(s.substr(i), t.substr(0, n - i))))
                return dp[key] = true;
        }
        return dp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        return helper_function(s1, s2);
    }
};