class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1,st2;
        for(auto it:s){
            if(it=='#' and !st1.empty()){
                st1.pop();
            }
            else if(it!='#'){
                st1.push(it);
            }
        }

        for(auto it:t){
            if(it=='#' and !st2.empty()){
                st2.pop();
            }
            else if(it!='#'){
                st2.push(it);
            }
        }

        if(st1==st2) return true;
        return false;
    }
};