class Solution {
public:
    #define ll long long
    unordered_map<string, ll> mp;
    vector<string> ans;
    void helper(string s, string t, ll ind) {
        if(ind == s.size()) {
            ans.push_back(t);
            return;
        }
        t += " ";
        ll n = s.size();
        for(ll i = ind; i < n; i++) {
            if(mp.find(s.substr(ind, i + 1 - ind)) != mp.end()) {
                helper(s, t + s.substr(ind, i + 1 - ind), i + 1);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it : wordDict)
            mp[it]++;
        ll n = s.size();
        for(ll i = 0; i < n; i++) {
            if(mp.find(s.substr(0, i + 1)) != mp.end()) {
                helper(s, s.substr(0, i + 1), i + 1);
            }
        }
        return ans;
    }
};