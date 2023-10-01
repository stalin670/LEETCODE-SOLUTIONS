class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string x="";
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                reverse(x.begin(),x.end());
                ans+=x;
                x="";
                ans+=' ';
            }
            else x+=s[i];
            if(i==n-1 and s[i]!=' '){
                reverse(x.begin(),x.end());
                ans+=x;
            }
        }
        return ans;
    }
};