class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        if (n <= 2) return n;

        vector<int> dp(n * n, 0), ar(n * n, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i * n + i] = 1;
            
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i * n + j] = (j - i == 1) ? 1 : dp[(i + 1) * n + (j - 1)];
                    ar[i * n + j] = 1 + ar[(i + 1) * n + (j - 1)];
                }
            }
        }

        for (int len = n; len >= 1; len--) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int k = ar[i * n + j];
                if (j <= i + 2 * k) {
                    return len;
                }
                if (dp[(i + k + 1) * n + (j - k)] || dp[(i + k) * n + ((j - k) - 1)]) {
                    return len;
                }
            }
        }

        return 0;
    }
};