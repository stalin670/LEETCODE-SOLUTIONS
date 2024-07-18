class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] != arr[(i + n - 1)%n] and arr[i] != arr[(i + 1)% n])
                ans++;
        }
        return ans;
    }
};