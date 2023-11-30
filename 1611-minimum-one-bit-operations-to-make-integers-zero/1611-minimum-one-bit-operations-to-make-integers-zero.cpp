class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans=0;
        bool ok=0;
        for(int i=31;i>=0;i--){
            if((n>>i)&1){
                if(!ok){
                    ans+=(1<<i);
                    ok=true;   
                }
                else ok=false;
            }
            else{
                if(ok) ans+=(1<<i);
            }
        }
        return ans;
    }
};