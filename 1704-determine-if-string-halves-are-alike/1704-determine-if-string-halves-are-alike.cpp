class Solution {
public:
    bool halvesAreAlike(string s) {
        string v="aeiouAEIOU";
        int f=0,t=0;
        for(int i=0;i<s.size();i++){
            bool ok=0;
            if(v.find(s[i])!=string::npos) ok=1;
            if(ok) t++;
            if(i<s.size()/2) if(ok) f++;
        }
        if(2*f==t) return true;
        return false;
    }
};