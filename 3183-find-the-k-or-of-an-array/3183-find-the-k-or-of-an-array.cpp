class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int mask=1<<i;
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mask & nums[j]) cnt++;
            }
            if(cnt>=k) ans+=(1<<i);
        }
        return ans;
    }
};