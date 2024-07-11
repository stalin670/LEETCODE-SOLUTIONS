class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> pos;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                pos.push(i);
            else if(s[i] == ')') {
                int start = pos.top() + 1;
                int end = i;
                reverse(s.begin() + start, s.begin() + i);
                pos.pop();
            }
        }
        
        string ans = "";
        for(auto it : s)
            if(it != '(' and it != ')')
                ans += it;
        return ans;
    }
};