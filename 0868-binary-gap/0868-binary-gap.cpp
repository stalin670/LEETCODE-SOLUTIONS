class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();
        s.erase(0, s.find('1'));

        int ans = 0, cnt = 0, ones = 0;
        for(auto ch: s) {
            if(ch == '0') cnt++;
            else {
                ones++;
                ans = max(ans, cnt + (ones > 1 ? 1 : 0));
                cnt = 0;
                if(ones > 1) ones = 1;
            }
        }
        return ans;
    }
};