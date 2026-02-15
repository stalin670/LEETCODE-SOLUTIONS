class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        int n = a.size(), m = b.size();
        string s = "";
        int i = 0, j = 0;
        while(i < n || j < m) {
            int sum = carry;

            if(i < n) sum += (a[i++] - '0');
            if(j < m) sum += (b[j++] - '0');

            s += char((sum % 2) + '0');
            carry = sum / 2;
        }

        if(carry) s += '1';

        reverse(s.begin(), s.end());
        return s;
    }
};