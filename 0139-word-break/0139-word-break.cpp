class Solution {
public:
    int len(string s){
        return s.size();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(len(s)+1,0);
        dp[len(s)]=1;
        for(int i=len(s)-1;i>=0;i--){
            for(auto word:wordDict){
                if(dp[i]) break;
                if((i+len(word))<=len(s) and s.substr(i,len(word))==word){
                    dp[i]=dp[i+len(word)];
                }
            }
        }
        return dp[0];
    }
};