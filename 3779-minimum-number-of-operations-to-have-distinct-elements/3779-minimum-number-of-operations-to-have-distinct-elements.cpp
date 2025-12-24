class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st;
        int idx = -1, n = nums.size();
        for(int i = n - 1; i >= 0; i--) {
            if(st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
            }
            else {
                idx = i + 1;
                break;
            }
        }
        if(idx == -1) return 0;
        int ans = (idx + 2) / 3;
        return ans;
    }
};