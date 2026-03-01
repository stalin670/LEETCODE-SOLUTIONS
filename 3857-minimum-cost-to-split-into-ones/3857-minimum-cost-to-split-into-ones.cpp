class Solution {
public:
    int minCost(int n) {
        if(n == 1) return 0;
        int last = 0, cur;
        for(int i = 2; i <= n; i++) {
            cur = (i - 1) + last;
            last = cur;
        }
        return last;
    }
};