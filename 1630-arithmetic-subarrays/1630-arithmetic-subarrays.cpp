class Solution {
public:
    bool check(vector<int> nums,int l,int r){
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=l;i<=r;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        
        int len=r-l+1;
        int diff=maxi-mini;
        if(diff%(len-1)!=0) return false;
        
        if(diff==0) return true;
        
        vector<bool> vis(len,false);
        
        for(int i=l;i<=r;i++){
            int val=nums[i];
            int curr=val-mini;
            int d=diff/(len-1);
            if(curr%d!=0){
                return false;
            }
            else{
                int pos=curr/d;
                if(vis[pos]) return false;
                vis[pos]=true;
            }
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            ans.push_back(check(nums,l[i],r[i]));
        }
        
        return ans;
    }
};