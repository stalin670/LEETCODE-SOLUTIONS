class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, ans = 0;
        bool ok = false;
        
        for(char x : s) {
            if(x == '0') {
                ok = true;
            }
            else {
                if(ok)
                    ans += ones;
                ones++;
                ok = false;
            }
        }
        if(ok)
            ans += ones;
        return ans;
    }
};