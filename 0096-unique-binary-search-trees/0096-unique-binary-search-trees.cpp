class Solution {
public:
    #define ll long long
    int numTrees(int n) {
        ll res = 1;
        ll k = n;
        ll N = 2 * n;
        if (k > N - k)
            k = N - k;

        for (int i = 0; i < k; ++i) {
            res *= (N - i);
            res /= (i + 1);
        }
        
        return res / (n + 1);
    }
};