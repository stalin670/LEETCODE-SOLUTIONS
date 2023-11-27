class Solution {
public:
    vector<int> countBits(int n) {
        // CHECK FOR ALL BIT 0 TO 31TH FOR ALL N
        // vector<int> ans;
        // for(int i=0;i<=n;i++){
        //     int t=0;
        //     int num=i;
        //     while(num){
        //         t++;
        //         num=num&(num-1);
        //     }
        //     ans.push_back(t);
        // }
        // return ans;
        
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            for(int j=0;j<32;j++){
                int mask=1<<j;
                if(i&mask) ans[i]++;
            }
        }
        return ans;
    }
};