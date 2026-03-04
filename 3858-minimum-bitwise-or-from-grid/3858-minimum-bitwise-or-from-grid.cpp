class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0;
        /*
            check msb to lsb and check whether we can keep the any bit
            to 0 or not ?
            if every row has atleast any element that fits within the current allowrd mask otherwise we need to set that bit 1.
        */
        for(int i = 21; i >= 0; i--) {
            int x = (1 << i);
            int mask = ans | (x - 1);
            for(auto vec : grid) {
                bool bad = true;
                for(auto val : vec) {
                    if((val & mask) == val) {
                        bad = false;
                        break;
                    }
                }
                if(bad) {
                    ans = ans | x;
                    break;
                }
            }
        }
        return ans;
    }
};