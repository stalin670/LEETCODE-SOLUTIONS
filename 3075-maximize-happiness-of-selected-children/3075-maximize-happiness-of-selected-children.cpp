#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll ans = 0;
        sort(happiness.rbegin(), happiness.rend());
        for(int i = 0; i < k; i++) {
            happiness[i] = max(happiness[i] - i, 0);
            ans = ans + happiness[i];
        }
        return ans;
    }
};