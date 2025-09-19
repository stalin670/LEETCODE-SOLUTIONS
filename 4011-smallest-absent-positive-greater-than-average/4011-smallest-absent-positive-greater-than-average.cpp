class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        set<int> st(nums.begin(), nums.end());
        int x = 1, n = nums.size();
        while(st.find(x) != st.end() or x * n <= sum) x++;
        return x;
    }
};