#define ll long long
class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1000000007;
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            string bin = bitset<32>(i).to_string();
            bin.erase(0, bin.find('1'));
            for(char ch : bin) {
                ans = (ans * 2) % mod;
                ans = (ans + (ch == '1' ? 1 : 0)) % mod;
            }
        }
        return ans;
    }
};