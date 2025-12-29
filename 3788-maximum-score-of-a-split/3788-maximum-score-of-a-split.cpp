#define ll long long
class Solution {
public:
    long long maximumScore(vector<int>& a) {
        ll n = a.size();
        vector<ll> pref(n), suff(n);
        pref[0] = a[0];
        suff[n - 1] = a[n - 1];

        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + a[i];
        }

        for(int i = n - 2; i >= 0; i--) {
            suff[i] = min(suff[i + 1], (ll)a[i]);
        }

        ll score = -100000000000000000;
        for(int i = 0; i < n - 1; i++) {
            score = max(score, pref[i] - suff[i + 1]);
        }
        return score;
    }
};