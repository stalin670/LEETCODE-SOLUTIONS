class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) {
            return {};
        }
        vector<pair<int, int>> a;
        for(int i = 0; i < arr.size(); i++) {
            a.push_back({arr[i], i});
        }
        sort(a.begin(), a.end());
        int x = 1;
        vector<int> ans(arr.size());
        ans[a[0].second] = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[a[i].second] == arr[a[i - 1].second]) {
                ans[a[i].second] = x;
            }
            else {
                ans[a[i].second] = x + 1;
                x++;
            }
        }
        return ans;
    }
};