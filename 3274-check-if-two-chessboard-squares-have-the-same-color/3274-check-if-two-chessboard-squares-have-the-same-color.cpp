class Solution {
public:
    #define ll long long
    bool checkTwoChessboards(string x, string y) {
        ll rowS = (x[0] - 'a') + (y[0] - 'a');
        ll colS = (x[1] - '0') + (y[1] - '0');
        return rowS % 2 == colS % 2;
    }
};