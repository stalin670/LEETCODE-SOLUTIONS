class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(char last,string s,int n){
        if(s.size()==n){
            return 1;
        }
        if(s.size()>n) return 0;

        int x=0;
        if(last=='a' ){
            s+='e';
            x+=f('e',s,n);
            s.pop_back();
        }
        else if(last=='e'){
            s+='a';
            x+=f('a',s,n);
            s.pop_back();
            s+='i';
            x+=f('i',s,n);
            s.pop_back();
        }
        else if(last=='i'){
            s+='a';
            x+=f('a',s,n);
            s.pop_back();
            s+='e';
            x+=f('e',s,n);
            s.pop_back();
            s+='o';
            x+=f('o',s,n);
            s.pop_back();
            s+='u';
            x+=f('u',s,n);
            s.pop_back();
        }
        else if(last=='o'){
            s+='a';
            x+=f('a',s,n);
            s.pop_back();
            s+='e';
            x+=f('e',s,n);
            s.pop_back();
            s+='o';
            x+=f('o',s,n);
            s.pop_back();
        }
        else if(last=='u'){
            s+='e';
            x+=f('e',s,n);
            s.pop_back();
            s+='i';
            x+=f('i',s,n);
            s.pop_back();
            s+='o';
            x+=f('o',s,n);
            s.pop_back();
            s+='u';
            x+=f('u',s,n);
            s.pop_back();
        }
        return x;
    }

    int countVowelPermutation(int n) {
        // string s="";
        // return f()

        vector<vector<long long>> dp(n, vector<long long>(5, 0));
        
        for (int i = 0; i < 5; ++i) {
            dp[0][i] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }
        
        long long ans = 0;
        for (int i = 0; i < 5; ++i) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
        
        return ans;
    }
};