class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int old = n;
        while(old) {
            int last = old % 10;
            old /= 10;
            rev = rev * 10 + last;
        }

        return abs(n - rev);
    }
};