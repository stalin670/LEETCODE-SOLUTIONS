#define ll long long
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll commonTake = min(need1, need2);
        ll costCommon = commonTake * costBoth;
        ll rest1 = costCommon + cost1 * (need1 - commonTake);
        rest1 += (ll)cost2 * ((ll)need2 - commonTake);

        ll rest2 = (ll)cost1 * (ll)need1 + (ll)cost2 * (ll)need2;

        ll rest3 = (ll)costBoth * (ll)max(need1, need2);

        ll ans = min({rest1, rest2, rest3});
        return ans;
    }
};