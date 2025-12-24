class Solution {
public:
/*
    if we can redistribute apples of same pack into different
    boxes then its just simple....

    sum it up all the apples

    just try to fill up boxes from higher capacity to lower.

*/
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int tot = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());
        int ans = 0;
        for(int i = 0; i < capacity.size(); i++) {
            if(tot > 0) {
                tot -= capacity[i];
                ans++;
            }
        }
        return ans;
    }
};