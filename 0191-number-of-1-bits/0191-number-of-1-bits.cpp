class Solution {
public:
    int hammingWeight(uint32_t n) {
        // ITERATE OVER ALL BITS 0 TO 31
        // int ans=0;
        // for(int i=0;i<32;i++){
        //     int mask=1<<i;
        //     if(mask&n) ans++;
        // }
        // return ans;
        
        // ONE OTHER WAY TO REMOVE EVERY SET BIT 
        int ans=0;
        while(n){
            ans++;
            n=n&(n-1);
        }
        return ans;
    }
};