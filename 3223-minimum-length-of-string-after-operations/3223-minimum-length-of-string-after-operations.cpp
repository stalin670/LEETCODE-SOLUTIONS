class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(n <= 2) 
            return n;
        if(n == 3) {
            if(s[0] == s[1] and s[1] == s[2]) {
                return 1;
            }
            else {
                return n;
            }
        }
        
        map<int,int> mp;
        for(auto &it : s)
            mp[it]++;
        int ans = n;
        for(auto it : mp) {
            if(it.second & 1) {
                ans -= (it.second - 1);
            }
            else {
                ans -= (it.second - 2);
            }
        }
        return ans;
    }
};