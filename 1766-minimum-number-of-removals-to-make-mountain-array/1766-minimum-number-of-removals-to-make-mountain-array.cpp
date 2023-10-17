class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp1(n,1),dp2(n,1);
        int ans = 0;
        
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <i; prev_index++){
                
                if(arr[i]>arr[prev_index] && 1 + dp1[prev_index] > dp1[i]){
                    dp1[i] = 1 + dp1[prev_index];
                }
            }
            // ans=max(ans,dp1[i]);
        }

        for(int i=n-1; i>=0; i--){
            for(int prev_index = n-1; prev_index >i; prev_index--){
                
                if(arr[i]>arr[prev_index] && 1 + dp2[prev_index] > dp2[i]){
                    dp2[i] = 1 + dp2[prev_index];
                }
            }
            // ans=max(ans,dp2[i]);
        }

        for(int i=0;i<n;i++){
            if(dp1[i]>1 and dp2[i]>1)
            ans=max(ans,dp1[i]+dp2[i]-1);
        }

        return n-ans;
    }
};