class Solution {
public:
/*
    1 <= n <= 10^5

    -> swapping i, j so that nums[i] != forbidden[j]
    -> min no. of swaps needed ???

    Observation:
    let's suppose cnt is the no. of index where nums[i] != forbidden[j]

    so, to fix these indexes we need
    ceil(cnt / 2) => (cnt + 1) / 2

    but but......
    do we have that much indexes to swap in those good position.

    let's suppose 
    1 2 3 2 2
    2 2 4 2 5


    here we can't swap, because we don't have enough indexes for 2.

    Another observation:
    if for v bad value
    if we have indexes >= n - pos[v] in forbidden array
    then -1. 
    coz we can't fix those positions, not enough indices.

    
    Another observation:
    let's suppose v is the value that appears maximum times in bad indexes
    than, we can fix this v, then we can fix every bad values.

    so now it is simple to check
    ans = max(v, (cnt + 1) / 2)
    v is the value that appears maximum times in bad indexes.

*/
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        int bad = 0;
        map<int, int> badmap;
        for(int i = 0; i < n; i++) {
            if(nums[i] == forbidden[i]) {
                bad++;
                badmap[nums[i]]++;
            }
        }

        map<int, int> mpnum, mpforb;
        for(int i = 0; i < n; i++) {
            mpnum[nums[i]]++;
            mpforb[forbidden[i]]++;
        }

        for(auto u : mpnum) {
            int k = u.first;
            int f = u.second;
            if(f + mpforb[k] > n)
                return -1;
        }

        int vmax = 0;
        for(auto u : badmap) {
            vmax = max(vmax, u.second);
        }

        int ans = max(vmax, (bad + 1) / 2);
        return ans;
    }
};