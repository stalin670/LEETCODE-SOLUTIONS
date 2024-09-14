class Solution {
public:
    #define ll long long
    int longestSubarray(vector<int>& arr) {
        ll maxi = *max_element(arr.begin(), arr.end());
        ll ans = 1, n = arr.size();
        ll i = 0, j = 0;
        while(j < n) {
            if(arr[j] == maxi) {
                i = j;
                while(j < n and arr[j] == maxi) {
                    ans = max(ans, j - i + 1);
                    j++;
                }
            }
            else {
                j++;
            }
        }
        return ans;
    }
};