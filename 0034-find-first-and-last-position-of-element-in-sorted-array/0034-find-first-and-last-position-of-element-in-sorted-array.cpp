class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int it1=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int it2=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        cout<<it1<<" "<<it2<<endl;
        if(it1==arr.size() || it2-1==arr.size() || arr[it1]!=x || arr[it2-1]!=x) return {-1,-1};
        return {it1,it2-1};
    }
};