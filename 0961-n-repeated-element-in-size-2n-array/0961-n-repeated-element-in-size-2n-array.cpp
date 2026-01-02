class Solution {
public:
/*
    n elements are unique
    sum should be (n * (n + 1)) / 2
    real sum is tot 

    take e.g.
    1 2 3 3
    sum = 6
    real_sum = 9

    extra_sum = 3
    now the repeated_element will be 
    extra_sum / (n - 1)
*/
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1])
                return nums[i];
        }
        return 1;
    }
};