class Solution {
public:
    int maxDepth(string s) {
        int x=0,curr=0;
        for(auto it:s){
            if(it=='('){
                curr++;
                x=max(x,curr);
            }
            else if(it==')') curr--;
        }
        return x;
    }
};