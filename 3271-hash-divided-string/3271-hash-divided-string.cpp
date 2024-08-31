class Solution {
public:
    #define ll long long
    string stringHash(string s, int k) {
        map<ll, char> mp;
        for(char x = 'a', i = 0; x <= 'z'; x++, i++) {
            mp[i] = x;
        }
        ll n = s.size();
        ll temp_sum = 0;
        string ans = "";
        ll curr_len = 0;
        for(ll i = 0; i < n; i++) {
            temp_sum += (s[i] - 'a');
            curr_len++;
            if(k == curr_len) {
                ans.push_back(mp[temp_sum % 26]);
                temp_sum = 0;
                curr_len = 0;
            }
        }
        
        return ans;
    }
};