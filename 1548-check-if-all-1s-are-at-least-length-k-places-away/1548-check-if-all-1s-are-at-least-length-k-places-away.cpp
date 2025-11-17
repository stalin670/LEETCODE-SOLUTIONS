class Solution {
public:
/*
    we can use extra O(n) space for storing the position of 1's

    or 

    just take 1 variable and store the position of first 1 and
    then just check each time the abs dist b/w them >= k then
    fine !!

*/
    bool kLengthApart(vector<int>& nums, int k) {
        int pos = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(pos == -1) pos = i;
                else {
                    int dist = i - pos - 1;
                    if(dist < k) return false;
                }
                pos = i;
            }
        }
        return true;
    }
};