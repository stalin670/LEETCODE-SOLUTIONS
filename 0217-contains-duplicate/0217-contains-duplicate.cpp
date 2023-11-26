class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // sort the array and check for the adjacent element
        // time nlogn with extra space is O(1)
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};