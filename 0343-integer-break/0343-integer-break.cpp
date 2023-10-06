class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        for (int k = 2; k <= n; k++) {
            int x = n / k;
            int rem = n % k;
            int product = pow(x + 1, rem) * pow(x, k - rem);
            ans = max(ans, product);
        }
        return ans;
    }
};