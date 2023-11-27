class Solution {
public:
    vector<int> countBits(int n) {
        // CHECK FOR ALL BIT 0 TO 31TH FOR ALL N
        // vector<int> ans(n+1,0);
        // for(int i=0;i<=n;i++){
        //     int num=i;
        //     while(num){
        //         ans[i]++;
        //         num=num&(num-1);
        //     }
        // }
        // return ans;
        
        // USING MASK
        // vector<int> ans(n+1,0);
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<32;j++){
        //         int mask=1<<j;
        //         if(i&mask) ans[i]++;
        //     }
        // }
        // return ans;
        
        // DP
        vector<int> dp(n+1,0);
        int offset=1;
        for(int i=1;i<=n;i++){
            if(2*offset == i) offset=i;
            dp[i]=1+dp[i-offset];
        }
        return dp;
    }
};