class Solution {
public:
    int maxOperations(string s) {
        /*
            The catch is that, if this was a minimum no. of moves instead of maximum
            then just count the number of ones if there is atleast 1 zero after them.

            but here we need to find the maximum moves!!

            Let's take,
            s = 1010011010101
            1 = 0110011010101
            
            just go with greedy
            count the ones,
            and when zero comes, increase the res with cur ones
        */

        int res = 0, ones = 0, found = 0;
        for(auto ch : s) { 
            if(ch == '0') {
                found = 1;
            }
            else {
                if(found) res += ones;
                found = 0;
                ones++;
            }
        }
        if(found) res += ones;
        return res;
    }
};