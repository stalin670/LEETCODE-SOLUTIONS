class Solution {
public:
    int countWays(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(i+1>arr[i] && (i<n-1 && arr[i+1]>i+1)) ans++;
            else if(arr[i]<i+1 && i+1==n) ans++;
        }
        if(arr[0]>0) ans++;
        
        return ans;
    }
};