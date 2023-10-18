class Solution {
public:
    int f(int i,int j,vector<int>&arr,vector<vector<int>>& dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        int cost=1e9;
        for(int k=i;k<=j;k++){
            int curr=(arr[j+1]-arr[i-1])+f(i,k-1,arr,dp)+f(k+1,j,arr,dp);
            if(curr<cost) cost=curr;
        }
        return dp[i][j]=cost;
    }

    int minCost(int n, vector<int>& cuts) {
        vector<int> arr;
        arr.push_back(0);
        for(auto it:cuts) arr.push_back(it);
        arr.push_back(n);
        sort(arr.begin(),arr.end());
        int sz=cuts.size();
        vector<vector<int>> dp(sz+1,vector<int>(sz+1,-1));
        // cout<<arr.size()<<endl;
        // for(auto it:arr) cout<<it<<" ";
        // cout<<endl;
        return f(1,sz,arr,dp);
    }
};