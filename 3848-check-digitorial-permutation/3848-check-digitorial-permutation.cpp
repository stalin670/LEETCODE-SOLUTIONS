class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10, 1);
        for(int i = 1; i < 10; i++) fact[i] = fact[i - 1] * i;

        int f = 0, num = n;
        while(n > 0) {
            int r = n % 10;
            n /= 10;
            f += fact[r];
        }

        string s = to_string(num);
        string t = to_string(f);

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};