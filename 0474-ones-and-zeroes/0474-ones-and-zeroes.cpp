class Solution {
public:
    int helper(int idx, int m, int n, vector<string>& strs, int sz, vector<vector<vector<int>>>& dp) {
        if(idx >= sz) return 0;

        if(dp[idx][m][n] != -1) return dp[idx][m][n];

        int cntz = 0, cnto = 0;
        for(auto ch : strs[idx]) {
            cntz += (ch == '0');
            cnto += (ch == '1');
        }

        int take = 0, notTake = 0;
        if(cntz <= m and cnto <= n) {
            take = 1 + helper(idx + 1, m - cntz, n - cnto, strs, sz, dp);
        }
        notTake = 0 + helper(idx + 1, m, n, strs, sz, dp);

        return dp[idx][m][n] = max(take, notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int z = strs.size();
        vector<vector<vector<int>>> dp(z, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        int ans = helper(0, m, n, strs, z, dp);
        return ans;
    }
};