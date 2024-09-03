class Solution {
public:
    #define ll long long
    int minSubArrayLen(int target, vector<int>& arr) {
        ll sum = 0;
        ll i = 0, j = 0, n = arr.size();
        ll ans = LLONG_MAX;
        while(j < n) {
            sum += arr[j];
            while(sum >= target) {
                if(sum >= target) {
                    ans = min(ans, j - i + 1);
                }
                sum -= arr[i];
                i++;
            }
            j++;
        }
        // cout << j - i + 1; 
        if(ans == LLONG_MAX)
            return 0;
        return ans;
    }
};