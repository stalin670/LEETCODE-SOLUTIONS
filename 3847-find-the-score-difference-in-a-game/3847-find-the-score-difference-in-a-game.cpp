class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        /*
            how can we know if at this index we need to swap or not ?
            -1, 5, 11, 17..... is an AP
            let's take index i
            11 = -1 + (n - 1) * 6
            12 / 6 = n - 1

            this condition should holds (i + 1) % d == 0

        
        */
        int first = 0, second = 0, active = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & 1)
                active = 1 - active;
            if((i + 1) % 6 == 0) 
                active = 1 - active;

            if(active) first += nums[i];
            else second += nums[i];
        }
        return first - second;
    }
};