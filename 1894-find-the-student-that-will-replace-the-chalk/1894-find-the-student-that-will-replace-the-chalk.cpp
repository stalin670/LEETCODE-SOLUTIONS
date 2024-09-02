class Solution {
public:
    #define ll long long
    int chalkReplacer(vector<int>& chalk, int k) {
        ll total_sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k = k % total_sum;
        for(ll i = 0; i < chalk.size(); i++) {
            if(chalk[i] > k)
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};