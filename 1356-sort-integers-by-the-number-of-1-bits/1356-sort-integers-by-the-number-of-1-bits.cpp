class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            int bits_x = __builtin_popcount(x);
            int bits_y = __builtin_popcount(y);
            if(bits_x != bits_y)
                return bits_x < bits_y;
            return x < y;    
        });
        return arr;
    }
};