class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        int left=0,right=0,ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            if(s[left]==s[right]){
                right++;
            }
            else{
                left=right;
                right++;
            }
            ans = (ans + (right-left))%mod;
        }
        return ans;
    }
};