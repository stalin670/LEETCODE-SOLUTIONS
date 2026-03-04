class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size(), m = mat[0].size();
        int row[n];
        int col[m];
        for(int i = 0; i < n; i++) {
            row[i] = count(mat[i].begin(), mat[i].end(), 1);
        }
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                cnt += mat[j][i];
            }
            col[i] = cnt;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1 and row[i] == 1 and col[j] == 1) ans++;
            }
        }
        return ans;
    }
};