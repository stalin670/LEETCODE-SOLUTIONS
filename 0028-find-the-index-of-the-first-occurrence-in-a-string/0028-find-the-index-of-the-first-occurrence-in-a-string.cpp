class Solution {
public:
    int strStr(string a, string b) {
        int n = a.size(), m = b.size();
        for(int i = 0; i <= n - m; i++) {
            bool ok = true;
            int j = 0, k = i;
            while(j < m) {
                if(a[k] != b[j]) {
                    ok = false;
                    break;
                }
                k++;
                j++;
            }
            if(ok)
                return i;
        }
        return -1;
    }
};