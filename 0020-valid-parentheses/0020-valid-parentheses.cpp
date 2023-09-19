class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }
            
            else if(s[i]==')'){
                if(st.empty()) return false;
                char c=st.top();
                st.pop();
                if(c=='{' || c=='['){
                    return false;
                    break;
                }
                
            }
            else if(s[i]=='}'){
                if(st.empty()) return false;
                char c=st.top();
                st.pop();
                if(c=='(' || c=='['){
                    return false;
                    break;
                }
                
            }
            else if(s[i]==']'){
                if(st.empty()) return false;
                char c=st.top();
                st.pop();
                if(c=='{' || c=='('){
                    return false;
                    break;
                }
                
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};