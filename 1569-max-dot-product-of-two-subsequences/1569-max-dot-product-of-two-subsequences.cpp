class Solution {
public:
    int f(int i,int j,vector<int>&arr,vector<int>&brr, vector<vector<int>>& dp){
        if(i==arr.size() and j==brr.size()) return INT_MIN;

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        dp[i][j] = max(
                arr[i] * brr[j] + max(f(i + 1, j + 1,arr,brr,dp), 0),
                max(f(i + 1, j,arr,brr,dp), f(i, j + 1,arr,brr,dp))
            );

        return dp[i][j];
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>> dp(n,vector<int>(m,INT_MIN));

        function<int(int, int)> f = [&](int i, int j) {
            if (i == n || j == m) {
                return INT_MIN;
            }
            
            if (dp[i][j] != INT_MIN) {
                return dp[i][j];
            }
            
            dp[i][j] = max(
                nums1[i] * nums2[j] + max(f(i + 1, j + 1), 0),
                max(f(i + 1, j), f(i, j + 1))
            );
            
            return dp[i][j];
        };

        return f(0,0);
    }
};