#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ll n = spells.size(), m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for(ll i = 0; i < n; i++) {
            ll lb = 0, rb = m - 1;
            ll idx = -1;
            while(lb <= rb) {
                ll mb = lb + (rb - lb) / 2;
                ll prod = (ll)spells[i] * (ll)potions[mb];
                if(prod >= success) {
                    idx = mb;
                    rb = mb - 1;
                }
                else lb = mb + 1;
            }
            if(idx == -1) ans[i] = 0;
            else ans[i] = m - idx;
        }
        return ans;
    }
};