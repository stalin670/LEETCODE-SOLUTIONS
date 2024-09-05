class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        ans.push_back(arr);
        vector<int> prev_perm = arr;
        while(next_permutation(arr.begin(), arr.end())) {
            if(arr != prev_perm) {
                prev_perm = arr;
                ans.push_back(arr);
            }
        }
        return ans;
    }
};