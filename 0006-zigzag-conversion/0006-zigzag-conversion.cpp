class Solution {
public:
    #define ll long long
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        map<ll, vector<char>> mp;
        ll x = 1;
        bool ok = true;
        for(ll i = 0; i < s.size(); i++) {
            mp[x].push_back(s[i]);
            if(ok) {
                x++;
                if(x == numRows) 
                    ok = false;
            }
            else {
                x--;
                if(x == 1)
                    ok = true;
            }
        }
        string ans = "";
        for(ll i = 1; i <= numRows; i++) {
            ll n = mp[i].size();
            vector<char> arr = mp[i];
            for(auto it : arr) 
                ans += it;
        }
        return ans;
    }
};