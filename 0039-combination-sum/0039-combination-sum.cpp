class Solution {
public:
    set<vector<int>> st;
    void helper(int idx, int sum, int n, vector<int>& a, int target, vector<int>& temp) {
        if(idx == n) {
            if(sum == target) {
                st.insert(temp);
            }
            return;
        }
        // take
        if(sum + a[idx] <= target) {
            temp.push_back(a[idx]);
            helper(idx, sum + a[idx], n, a, target, temp);
            temp.pop_back();
        }
        // nottake
        helper(idx + 1, sum, n, a, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        int sum = 0;
        helper(0, sum, n, candidates, target, temp);
        for(auto vec : st) ans.push_back(vec);
        return ans;
    }
};