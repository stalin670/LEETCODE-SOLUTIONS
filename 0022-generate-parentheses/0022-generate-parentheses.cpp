class Solution {
public:
    #define ll long long
    vector<string> ans;
    void helper(ll open, ll close, ll total, string x) {
        if(x.size() == total) {
            ans.push_back(x);
            return;
        }
        
        if(open < total / 2) {
            x += '(';
            helper(open + 1, close, total, x);
            x.pop_back();
        }
        if(open > close) {
            x += ')';
            helper(open, close + 1, total, x);
        }
    }
    vector<string> generateParenthesis(int n) {
        string x = "";
        ll total = 2 * n;
        helper(0, 0, total, x);
        return ans;
    }
};