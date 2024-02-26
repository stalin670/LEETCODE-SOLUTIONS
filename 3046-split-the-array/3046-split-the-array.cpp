class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        for(auto it:nums)
            if(count(nums.begin(),nums.end(),it)>2) return false;
        return true;
    }
};