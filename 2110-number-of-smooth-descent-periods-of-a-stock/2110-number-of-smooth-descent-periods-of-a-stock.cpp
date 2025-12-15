#define ll long long
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        /**
            the idea is simple, 
            we can use two pointer i, j
            i.......j it is decreasing subarray

            we can add (len * (len + 1)) / 2
            len = j - i + 1;
        **/
        ll n = prices.size();
        if(n == 1) return 1;
        ll i = 0, j = 1, ans = 0;
        while(j < n) {
            if(prices[j] - prices[j - 1] == -1) j++;
            else {
                ll len = j - i;
                ans += (len * (len + 1)) / 2;
                i = j;
                j++;
            }
        }
        ll len = j - i;
        if(len >= 1) {
            ans += (len * (len + 1)) / 2;
        }
        return ans;
    }
};