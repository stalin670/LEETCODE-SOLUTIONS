class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for(int i = 0; i < digits.size(); i++) {
            digits[i] += carry;
            if(digits[i] > 9) {
                digits[i] = 0;
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        if(carry) {
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};