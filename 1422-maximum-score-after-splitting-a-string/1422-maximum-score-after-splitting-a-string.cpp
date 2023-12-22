class Solution {
public:
    int maxScore(string s) {
        int cnt=0;
        for(auto it:s) cnt+=(it=='1');
        int ans=0,x=0;
        for(int i=0;i<size(s)-1;i++){
            x+=(s[i]=='0');
            cnt-=(s[i]=='1');
            ans=max(ans,x+cnt);
        }
        return ans;
    }
};