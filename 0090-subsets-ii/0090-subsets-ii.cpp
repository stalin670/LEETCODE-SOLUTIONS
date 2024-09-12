class Solution {
public:
    set<vector<int>> st;
    void helper_function(int ind, int n, vector<int>& a, vector<int>& nums) {
        if(ind >= n) {
            st.insert(a);
            return;
        }
        
        a.push_back(nums[ind]);
        helper_function(ind + 1, n, a, nums);
        a.pop_back();
        helper_function(ind + 1, n, a, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        st.insert({});
        int n = nums.size();
        vector<int> a;
        helper_function(0, n, a, nums);
        vector<vector<int>> ans;
        for(auto &it : st)
            ans.push_back(it);
        return ans;
    }
};