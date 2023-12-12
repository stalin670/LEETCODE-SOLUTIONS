class Solution {
public:
    bool check(int x,vector<int> arr){
        int cnt=0;
        for(auto it:arr){
            if(it<=x) cnt++;
        }
        return cnt>x;
    }
    
    int findDuplicate(vector<int>& nums) {
        int lo=1,hi=size(nums)-1;
        int ans;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,nums)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};