class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> stk;
        for(auto x : nums) {
            while(!stk.empty() and stk.back() > x)
                stk.pop_back();
            if(x == 0) continue;
            if(stk.empty() or stk.back() != x) {
                ans++;
                stk.push_back(x);
            }
        }
        return ans;
    }
};