class Solution {
public:
    string largestOddNumber(string s) {
        int last=-1;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9'){
                last=i;
                break;
            }
        }
        if(last==-1) return "";
        string ans="";
        for(int i=0;i<=last;i++){
            ans+=s[i];
        }
        return ans;
    }
};