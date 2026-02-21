#define ll long long
class Solution {
public:
    const int N = 1000005;
    int countPrimeSetBits(int left, int right) {
        vector<ll> isPrime(N, 1);
        isPrime[0] = isPrime[1] = 0;
        for(ll i = 2; i < N; i++) {
            if(isPrime[i] == 1) {
                for(ll j = i * i; j < N; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        int ans = 0;
        for(ll i = left; i <= right; i++) {
            ll bits = __builtin_popcountll(i);
            if(isPrime[bits] == 1)
                ans++;
        }
        return ans;
    }
};