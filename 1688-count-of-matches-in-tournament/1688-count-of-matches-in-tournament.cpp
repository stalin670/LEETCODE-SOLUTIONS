class Solution {
public:
    int numberOfMatches(int n) {
        int ans=0;
        while(n!=1){
            ans+=(n/2);
            if(n&1) n=(n+1)/2;
            else n/=2;
        }
        return ans;
    }
};