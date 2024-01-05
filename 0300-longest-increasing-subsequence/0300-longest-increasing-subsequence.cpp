class Solution {
public:
    int f(int ind,int prev,vector<int> arr,vector<vector<int>>& dp){
        if(ind==size(arr)) return 0;
        if(dp[ind][1+prev]!=-1) return dp[ind][prev];
        
        int notPick = 0+f(ind+1,prev,arr,dp);
        int pick=0;
        
        if(prev==-1 || arr[ind]>arr[1+prev]){
            pick = 1+f(ind+1,ind,arr,dp);
        }
        
        return dp[ind][1+prev]=max(pick,notPick);
    }
    
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> t;
        t.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>t.back()){
                t.push_back(arr[i]);
            }
            else{
                int ind=lower_bound(t.begin(),t.end(),arr[i])-t.begin();
                t[ind]=arr[i];
            }
        }
        return t.size();
        
        vector<vector<int>> dp(size(arr),vector<int>(size(arr)+1,-1));
        return f(0,-1,arr,dp);
    }
};