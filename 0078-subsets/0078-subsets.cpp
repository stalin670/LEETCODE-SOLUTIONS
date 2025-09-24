class Solution {
public:
    set<vector<int>> st;
    void helper(int i, int n, vector<int>& a, vector<int> &temp) {
        if(i == n) {
            st.insert(temp);
            return;
        }
        // take 
        temp.push_back(a[i]);
        helper(i + 1, n, a, temp);
        // notTake
        temp.pop_back();
        helper(i + 1, n, a, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        helper(0, n, nums, temp);
        vector<vector<int>> ans;
        for(auto vec : st) ans.push_back(vec);
        return ans;
    }
};