class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0)
                mp[nums[i] % value]++;
            else {
                int times = (abs(nums[i]) + (value - 1)) / value;
                int val = nums[i] + times * value;
                mp[val % value]++;
            }
        }
        int mex = 0;
        while(1) {
            int need = mex % value;
            if(mp.find(need) != mp.end()) {
                mp[need]--;
                if(mp[need] == 0) {
                    mp.erase(need);
                }
            }
            else break;
            mex++;
        }
        return mex;
    }
};