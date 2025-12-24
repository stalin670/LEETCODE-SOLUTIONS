class Solution {
public:
/*  
    we can separate numbers based on num % 3...
    and try to check all possible combination to form
    sum % 3 == 0

    0 + 0 + 0
    1 + 1 + 1
    2 + 2 + 2
    0 + 1 + 2
*/
    int maximumSum(vector<int>& a) {
        vector<int> z, o, t;
        for(auto &x : a) {
            if(x % 3 == 0) z.push_back(x);
            else if(x % 3 == 1) o.push_back(x);
            else t.push_back(x);
        }
        sort(o.rbegin(), o.rend());
        sort(z.rbegin(), z.rend());
        sort(t.rbegin(), t.rend());
        int ans = 0;
        if(z.size() >= 3) {
            ans = max(ans, z[0] + z[1] + z[2]);
        }
        if(o.size() >= 3) {
            ans = max(ans, o[0] + o[1] + o[2]);
        }
        if(t.size() >= 3) {
            ans = max(ans, t[0] + t[1] + t[2]);
        }
        if(z.size() >= 1 and o.size() >= 1 and t.size() >= 1) {
            ans = max(ans, z[0] + o[0] + t[0]);
        }

        return ans;
    }
};