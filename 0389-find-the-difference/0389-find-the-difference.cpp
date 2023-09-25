class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        char ans=' ';
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                ans=t[i];
                break;
            }
        }
        if(ans==' '){
            ans=t[t.size()-1];
        }
        return ans;
    }
};