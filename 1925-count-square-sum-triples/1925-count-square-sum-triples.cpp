class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                int x = i * i + j * j;
                int sq = sqrt(x);
                if(x == sq * sq and sq <= n) ans++;
            }
        }
        return ans;
    }
};