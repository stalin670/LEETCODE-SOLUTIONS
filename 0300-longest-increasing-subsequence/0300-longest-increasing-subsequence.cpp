class Solution {
public:
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
    }
};