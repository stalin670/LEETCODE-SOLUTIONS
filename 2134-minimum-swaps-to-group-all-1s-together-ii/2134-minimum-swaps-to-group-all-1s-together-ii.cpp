class Solution {
public:
    #define ll long long
    int minSwaps(vector<int>& nums) {
        ll cntOnes = 0;
        for(auto it : nums)
            cntOnes += (it == 1);
        ll n = nums.size();
        ll maxOnes = 0;
        for(ll i = 0; i < cntOnes; i++)
            maxOnes += (nums[i] == 1);
        ll i = 0, j = cntOnes - 1;
        ll window = maxOnes;
        while(j < 2 * n) {
            j++, i++;
            if(j == 2 * n)
                break;
            maxOnes += (nums[j % n] == 1);
            maxOnes -= (nums[(i - 1) % n] == 1);
            window = max(window, maxOnes);
        }
        return cntOnes - window;
    }
};