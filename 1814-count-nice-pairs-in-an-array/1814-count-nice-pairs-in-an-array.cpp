class Solution {
public:
    const int mod=1e9+7;
    int rev(int n){
        int reverseNum=0;
        while(n){
            reverseNum=reverseNum*10 + n%10;
            n/=10;
        }
        return reverseNum;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int reverseNum=rev(nums[i]);
            nums[i]-=reverseNum;
            if(mp[nums[i]]){
                ans = (ans + mp[nums[i]] % mod )%mod;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};