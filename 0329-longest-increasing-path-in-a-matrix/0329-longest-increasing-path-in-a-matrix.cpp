class Solution {
public:
    int dfs(int r, int c, int prevVal, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m || matrix[r][c] <= prevVal) {
            return 0;
        }
        
        if(dp[r][c] != -1) {
            return dp[r][c];
        }
        
        int maxi = 1;
        maxi = max(maxi, 1 + dfs(r + 1, c, matrix[r][c], matrix, dp));
        maxi = max(maxi, 1 + dfs(r - 1, c, matrix[r][c], matrix, dp));
        maxi = max(maxi, 1 + dfs(r, c + 1, matrix[r][c], matrix, dp));
        maxi = max(maxi, 1 + dfs(r, c - 1, matrix[r][c], matrix, dp));
        
        dp[r][c] = maxi;
        return maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, -1, matrix, dp));
            }
        }
        return ans;
    }
};