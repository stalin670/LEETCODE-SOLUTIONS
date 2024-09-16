class Solution {
public:
    #define ll long long
    int mySqrt(int x) {
        ll ans;
        ll lb = 0, rb = 1e8;
        while(lb <= rb) {
            ll mb = lb + (rb - lb) / 2;
            if(mb * mb <= x) {
                ans = mb;
                lb = mb + 1;
            }
            else {
                rb = mb - 1;
            }
        }
        return ans;
    }
};