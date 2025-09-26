class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int left = arr[0], right = arr[0];
        int ans = 0, i = 0, j = 0;
        int lastdone = 0;
        while(j < n) {
            if(left == i and right == j) {
                ans++;
                if(j == n - 1) {
                    lastdone++;
                    break;
                }
                else {
                    left = arr[j + 1];
                    right = arr[j + 1];
                    i = j + 1;
                    j++;
                }
            }
            else {
                j++;
                left = min(left, arr[j]);
                right = max(right, arr[j]);
            }
        }
        if(lastdone == 0)
            ans++;
        return ans;
    }
};