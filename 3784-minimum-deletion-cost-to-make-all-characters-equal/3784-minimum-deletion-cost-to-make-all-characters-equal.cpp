class Solution {
public:
#define ll long long
    long long minCost(string s, vector<int>& cost) {
        map<char, ll> costmp;

        ll n = cost.size();
        for(ll i = 0; i < n; i++) {
            costmp[s[i]] += cost[i];
        }

        if(costmp.size() == 1) return 0;

        ll mincost = 1000000000000000;
        for(auto u : costmp) {
            char ch = u.first;
            ll curcost = 0;
            for(auto v : costmp) {
                if(ch != v.first) {
                    curcost += v.second;
                }
            }
            mincost = min(mincost, curcost);
        }
        return mincost;
    }
};