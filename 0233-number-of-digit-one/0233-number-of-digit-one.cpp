class Solution {
public:
    #define ll long long
    int countDigitOne(int n) {
        string s = to_string(n);
        ll sz = s.size();
        ll ans = 0;
        for(ll i = 0; i < sz; i++) {
            if(s[i] == '0')
                continue;
            else if(s[i] != '1') {
                ll pw = sz - i - 1;
                ll curr_digit = 1;
                for(ll x = 1; x <= pw; x++) {
                    curr_digit *= 10;
                }
                ll lower_digit = (curr_digit / 10) * pw;
                lower_digit = (s[i] - '0') * lower_digit;
                ll total = lower_digit + curr_digit;
                ans += total;
            }
            else {
                if(i == sz - 1) {
                    ans++;
                }
                else {
                    ll cur_digit = 0;
                    for(ll j = i + 1; j < sz; j++) {
                        cur_digit = cur_digit * 10 + (s[j] - '0');
                    }
                    cur_digit++;
                    ll pw = sz - i - 1;
                    ll y = 1;
                    for(ll x = 1; x <= pw; x++) {
                        y *= 10;
                    }
                    ll lower_digit = (pw * y) / 10;
                    ll total = lower_digit + cur_digit;
                    ans += total;
                }
            }
        }
        return ans;
    }
};