class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2, a = -1, b = -1;
        multiset<int> mst(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) mst.erase(mst.find(i));
        vector<int> ans;
        for(auto x : mst) ans.push_back(x);
        return ans;
    }
};