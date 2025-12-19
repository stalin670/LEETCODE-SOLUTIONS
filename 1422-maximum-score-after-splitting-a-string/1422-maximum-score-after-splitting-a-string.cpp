class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int pref0[n];
        int suff1[n];
        pref0[0] = (s[0] == '0' ? 1 : 0);
        suff1[n - 1] = (s[n - 1] == '1' ? 1 : 0);
        for(int i = 1; i < n; i++) {
            pref0[i] = pref0[i - 1] + (s[i] == '0' ? 1 : 0);
        }

        for(int i = n - 2; i >= 0; i--) {
            suff1[i] = suff1[i + 1] + (s[i] == '1' ? 1 : 0);
        }
        int maxScore = 0;
        for(int i = 0; i < n - 1; i++) {
            maxScore = max(maxScore, pref0[i] + suff1[i + 1]);
        }
        return maxScore;
    }
};