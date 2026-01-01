class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        reverse(digits.begin(), digits.end());
        int n = digits.size();
        int carry = 1;

        for(int i = 0; i < n; i++) {
            int d = digits[i] + carry;
            if(d >= 10) carry = 1;
            else carry = 0;
            ans.push_back(d % 10);
        }

        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};