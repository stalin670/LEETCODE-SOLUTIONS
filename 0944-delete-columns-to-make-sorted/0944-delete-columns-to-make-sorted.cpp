class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, n = strs.size(), m = strs[0].size();
        for(int j = 0; j < m; j++) {
            for(int i = 1; i < n; i++) {
                char last = strs[i - 1][j], cur = strs[i][j];
                if(last > cur) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};