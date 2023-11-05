class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],arr[i]);
        }
        int ans=-1;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(prefix[i]==prefix[i-1]){
                cnt++;
                if(cnt>=k){
                    ans=prefix[i];
                    return prefix[i];
                }
            }
            else{
                if(prefix[i]>prefix[i-1]) cnt=1;
                else cnt=0;
                if(cnt>=k){
                    ans=prefix[i];
                    return prefix[i];
                }
            }
        }
        int maxi=arr[0];
        for(auto it:arr) maxi=max(maxi,it);
        return maxi;
    }
};