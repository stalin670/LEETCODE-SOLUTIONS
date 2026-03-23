#define ll long long
#define mod 1000000007
class Solution {
public:
    int maxProductPath(vector<vector<int>>& a) {
        ll n = a.size(), m = a[0].size();
        vector<vector<ll>> dpmax(n, vector<ll>(m)), dpmin(n, vector<ll>(m));

        dpmin[0][0] = dpmax[0][0] = a[0][0];
        for(int i = 1; i < n; i++) {
            dpmax[i][0] = dpmax[i - 1][0] * a[i][0];
            dpmin[i][0] = dpmax[i][0];
        }
        for(int i = 1; i < m; i++) {
            dpmax[0][i] = dpmax[0][i - 1] * a[0][i];
            dpmin[0][i] = dpmax[0][i];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                ll val1 = dpmax[i - 1][j] * a[i][j];
                ll val2 = dpmin[i - 1][j] * a[i][j];
                ll val3 = dpmax[i][j - 1] * a[i][j];
                ll val4 = dpmin[i][j - 1] * a[i][j];
                dpmax[i][j] = max({val1, val2, val3, val4});
                dpmin[i][j] = min({val1, val2, val3, val4});
            }
        }
        if(dpmax[n - 1][m - 1] < 0) return -1;
        int ans = dpmax[n - 1][m - 1] % mod;
        return ans;
    }
};