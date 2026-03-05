class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i & 1) {
                if(s[i] != '1') ans1++;
                else ans2++;
            }
            else {
                if(s[i] != '1') ans2++;
                else ans1++;
            }
        }
        return min(ans1, ans2);
    }
};