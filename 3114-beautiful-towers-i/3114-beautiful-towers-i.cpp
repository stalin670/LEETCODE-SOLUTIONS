class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        int n=arr.size();
        long long ans=-1;
        for(int i=0;i<n;i++){
            int ind=i;
            long long sum=arr[ind];
            long long maxx=arr[ind];
            for(int i=ind-1;i>=0;i--){
                if(arr[i]==maxx) sum+=arr[i];
                else if(arr[i]>maxx){
                    sum+=maxx;
                }
                else{
                    maxx=arr[i];
                    sum+=maxx;
                }
            }
            maxx=arr[ind];
            for(int i=ind+1;i<n;i++){
                if(arr[i]==maxx) sum+=arr[i];
                else if(arr[i]>maxx){
                    sum+=maxx;
                }
                else{
                    maxx=arr[i];
                    sum+=maxx;
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};