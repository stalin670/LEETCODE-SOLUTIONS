class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int first = (start >> (i)) % 2;
            int second = (goal >> (i)) % 2;
            if(first != second)
                ans++;
        }
        return ans;
    }
};