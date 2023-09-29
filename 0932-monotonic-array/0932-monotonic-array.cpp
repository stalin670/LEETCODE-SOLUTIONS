class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
        int n=arr.size();
        if(arr[0]<=arr[n-1]){
            for(int i=0;i<n-1;i++){
                if(arr[i]>arr[i+1]) return false;
            }
        }
        else{
            for(int i=0;i<n-1;i++){
                if(arr[i]<arr[i+1]) return false;
            }
        }
        return true;
    }
};