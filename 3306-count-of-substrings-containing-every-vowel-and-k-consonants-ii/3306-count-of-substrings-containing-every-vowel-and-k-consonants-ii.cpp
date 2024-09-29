#define ll long long
const ll MAX = 2e5 + 1;
ll pref[MAX][5];
class Solution {
public:
    long long countOfSubstrings(string s, int k) {
        ll n = s.size(), ans = 0;
        string v = "aeiou";
        // for(ll i = 0; i <= n; i++) {
            for(ll j = 0; j < 5; j++) {
                pref[0][j] = 0;
            }
        // }
        
        auto index = [&](char ch) {
            for(int i = 0; i < 5; i++) {
                if(v[i] == ch)
                    return i;
            }
            return -1;
        };
        
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < 5; j++) {
                pref[i + 1][j] = pref[i][j];
            }
            int idx = index(s[i]);
            if(idx != -1)
                pref[i + 1][idx]++;
        }
        
        // for(ll i = -1; i < n; i++) {
        //     for(auto ch : v) {
        //         cout << pref[i + 1][ch - 'a'] << " ";
        //     }
        //     cout << endl;
        // }
        
        auto getVowels = [&](ll i, ll j) {
            ll count = 0;
            for(ll id = 0; id < 5; id++) {
                ll left = pref[j + 1][id] - pref[i][id];
                if(left)
                    count++;
            }
            return count;
        };
        
        auto getConsonent = [&](ll i, ll j) {
            ll gap = j - i + 1;
            ll count = 0;
            for(ll id = 0; id < 5; id++) {
                ll left = pref[j + 1][id] - pref[i][id];
                count += left;
            }
            return gap - count;
        };
        
        auto firstGreaterK = [&](ll st) {
            ll lb = st, rb = n - 1;
            ll possible = n;
            while(lb <= rb) {
                ll mb = lb + (rb - lb) / 2;
                ll conso = getConsonent(st, mb);
                ll vowels = getVowels(st, mb);
                if(vowels == 5 and conso >= k) {
                    possible = mb;
                    rb = mb - 1;
                }
                else {
                    lb = mb + 1;
                }
            }
            return possible;
        };
        
        auto lastGreaterK = [&](ll st) {
            ll lb = st, rb = n - 1;
            ll possible = lb - 1;
            while(lb <= rb) {
                ll mb = lb + (rb - lb) / 2;
                ll conso = getConsonent(st, mb);
                if(conso <= k) {
                    possible = mb;
                    lb = mb + 1;
                }
                else {
                    rb = mb - 1;
                }
            }
            return possible;
        };
        
        auto firstAllVowel = [&](ll st) {
            ll lb = st, rb = n;
            ll possible = -1;
            while(lb <= rb) {
                ll mb = lb + (rb - lb) / 2;
                ll vowels = getVowels(st, mb);
                if(vowels >= 5) {
                    possible = mb;
                    rb = mb - 1;
                }
                else {
                    lb = mb + 1;
                }
            }
            return possible;
        };
        
        for(ll i = 0; i < n; i++) {
            ll e1 = firstGreaterK(i);
            ll e2 = lastGreaterK(i);
            // ll e3 = firstAllVowel(i);
            // cout << e1 << " " << e2 << " " << e3 << endl;
            if(e1 <= e2)
                ans += e2 - e1 + 1;
        }
        return ans;
    }
};