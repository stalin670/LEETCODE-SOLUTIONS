class Solution {
public:
    #define ll long long
    int getLucky(string s, int k) {
        ll total_sum = 0;
        for(auto &ch : s) {
            ll cur_sum = (ch - 'a' + 1);
            while(cur_sum) {
                total_sum += cur_sum % 10;
                cur_sum /= 10;
            }
        }
        while(k > 1) {
            ll cur_sum = total_sum;
            total_sum = 0;
            while(cur_sum) {
                total_sum += cur_sum % 10;
                cur_sum /= 10;
            }
            k--;
        }
        return total_sum;
    }
};