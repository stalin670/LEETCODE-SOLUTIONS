class Solution {
public:
    vector<int> countBits(int n) {
        // CHECK FOR ALL BIT 0 TO 31TH FOR ALL N
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int t=0;
            int num=i;
            while(num){
                t++;
                num=num&(num-1);
            }
            ans.push_back(t);
        }
        return ans;
    }
};