class Solution {
public:
    #define ll long long
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ll sum = 0;
        ll m = rolls.size();
        for(auto it : rolls)
            sum += it;
        ll need = (n + m) * mean - sum;
        vector<int> ans;
        if(6 * n  < need || n > need)
            return ans;
        ll atleast = need / n;
        ll extra = need % n;
        for(ll i = 1; i <= n; i++) {
            ans.push_back(atleast);
        }
        ll i = 0;
        while(extra > 0 and i < n) {
            ll max_can = 6 - ans[i];
            ans[i] += min(extra, max_can);
            extra -= min(extra, max_can);
            i++;
        }
        return ans;
    }
};