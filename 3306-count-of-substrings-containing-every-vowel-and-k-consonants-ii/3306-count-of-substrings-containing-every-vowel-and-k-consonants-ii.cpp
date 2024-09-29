#define ll long long
const ll MAX = 2e5 + 1;
ll pref[MAX][5];
class Solution {
public:
    long long countOfSubstrings(string s, int k) {
        ll n = s.size(), ans = 0;
        string v = "aeiou";
        for(ll j = 0; j < 5; j++) {
            pref[0][j] = 0;
        }
        
        auto index = [&](char ch) {
            for(int i = 0; i < 5; i++) {
                if(v[i] == ch)
                    return i;
            }
            return -1;
        };
        
        // Creating Prefix Array for Vowels
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < 5; j++) {
                pref[i + 1][j] = pref[i][j];
            }
            int idx = index(s[i]);
            if(idx != -1)
                pref[i + 1][idx]++;
        }
        
        // Getting Vowels between i and j
        auto getVowels = [&](ll i, ll j) {
            ll count = 0;
            for(ll id = 0; id < 5; id++) {
                ll left = pref[j + 1][id] - pref[i][id];
                if(left)
                    count++;
            }
            return count;
        };
        
        // Getting Consonenets between i and j
        auto getConsonent = [&](ll i, ll j) {
            ll gap = j - i + 1;
            ll count = 0;
            for(ll id = 0; id < 5; id++) {
                ll left = pref[j + 1][id] - pref[i][id];
                count += left;
            }
            return gap - count;
        };
        
        // Function to find the smallest index for allVowels and Cons >= k
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
        
        // Function to find the greatest index for which consonents >= k
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
        
        // Iterating all the string
        for(ll i = 0; i < n; i++) {
            // Simple Binary search
            ll e1 = firstGreaterK(i);
            ll e2 = lastGreaterK(i);
            if(e1 <= e2)
                ans += e2 - e1 + 1;
        }
        return ans;
    }
};