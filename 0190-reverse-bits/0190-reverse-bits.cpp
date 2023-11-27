class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans=0;
        for(int i=0;i<32;i++){
            int mask=1<<i;
            if(mask&n){
                int msk=1<<(31-i);
                ans|=msk;
            }
        }
        return ans;
    }
};