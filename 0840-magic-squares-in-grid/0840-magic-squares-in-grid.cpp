class Solution {
public:

    bool checker(vector<vector<int>>& ar) {
        set<int> st;
        set<int> sum;
        for(int i = 0; i < 3; i++) {
            int s1 = 0, s2 = 0;
            for(int j = 0; j < 3; j++) {
                s1 += ar[i][j];
                s2 += ar[j][i];
                st.insert(ar[i][j]);
            }
            sum.insert(s1);
            sum.insert(s2);
        }
        sum.insert(ar[0][0] + ar[1][1] + ar[2][2]);
        sum.insert(ar[0][2] + ar[1][1] + ar[2][0]);
        if(st.size() != 9 or sum.size() != 1 or *st.begin() != 1 or *st.rbegin() != 9) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if(n < 3 or m < 3) return 0;

        int ans = 0;

        int row1 = 0, row2 = 2;
        while(row2 < n) {
            int col1 = 0, col2 = 2;
            while(col2 < m) {
                vector<vector<int>> ar(3, vector<int>(3));
                for(int i = row1; i <= row2; i++) {
                    for(int j = col1; j <= col2; j++) {
                        ar[i - row1][j - col1] = grid[i][j];
                    }
                }

                if(checker(ar)) ans++;

                col1++;
                col2++;
            }
            row1++;
            row2++;
        }
        
        return ans;
    }
};