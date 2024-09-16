class Solution {
public:
    // Simple Addition from Back side
    string addBinary(string a, string b) {
        string s = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while(i >= 0 and j >= 0) {
            int x = a[i] - '0';
            int y = b[j] - '0';
            int z = x + y + carry;
            if(z > 1) {
                carry = 1;
                if(z == 2) 
                    s += '0';
                else
                    s += '1';
            }
            else {
                carry = 0;
                if(z == 1) 
                    s += '1';
                else
                    s += '0';
            }
            i--;
            j--;
        }
        
        while(i >= 0) {
            int x = a[i] - '0';
            int z = x + carry;
            if(z > 1) {
                carry = 1;
                s += '0';
            }
            else {
                carry = 0;
                if(z == 1) 
                    s += '1';
                else
                    s += '0';
            }
            i--;
        }
        while(j >= 0) {
            int y = b[j] - '0';
            int z = y + carry;
            if(z > 1) {
                carry = 1;
                s += '0';
            }
            else {
                carry = 0;
                if(z == 1) 
                    s += '1';
                else
                    s += '0';
            }
            j--;
        }
        
        if(carry) {
            s += '1';
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};