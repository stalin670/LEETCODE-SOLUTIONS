class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int full_week = n / 7;
        int left_days = n - (full_week * 7);
        for(int i = 1; i <= left_days; i++) {
            ans += full_week + i;
        }
        /*
            7 * (7 + 1) / 2 = 28
            AP = 28 + 7 * 0, 28 + 7 * 1, 28 + 7 * 2
            a = 28
            d = 7
            n = full_week
            Sn = (n / 2) * [2 * a + (n - 1) * d]
        */
        int a = 28, d = 7;
        int Last_term = 2 * a + (full_week - 1) * d; 
        int Sn = (full_week * Last_term) / 2;
        ans += Sn;
        return ans;
    }
};