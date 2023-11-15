class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1) arr[0]=1;
        for(int i=1;i<arr.size();i++){
            int diff=arr[i]-arr[i-1];
            if(diff<=1) continue;
            arr[i]=arr[i-1]+1;
        }
        return arr[arr.size()-1];
    }
};