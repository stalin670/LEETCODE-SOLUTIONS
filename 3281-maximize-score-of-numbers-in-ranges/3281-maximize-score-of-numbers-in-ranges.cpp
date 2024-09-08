class Solution {
public:
    #define ll long long
    #define inf 10000000000
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        ll lb = 0, rb = inf;
        ll ans;
        
        auto helper_function = [&](ll k) {
            ll last = start[0];
            for(ll i = 1; i < start.size(); i++) {
                ll l = start[i];
                ll r = start[i] + d;
                if(last + k >= l and last + k <= r) {
                    last = last + k;
                }
                else if(l >= last + k) {
                    last = l;
                }
                else
                    return false;
            }
            return true;
        };
        
        while(lb <= rb) {
            ll mb = lb + (rb - lb) / 2;
            if(helper_function(mb)) {
                ans = mb;
                lb = mb + 1;
            }
            else {
                rb = mb - 1;
            }
        }
        return ans;
    }
};