class Solution {
public:
    #define ll long long
    vector<int> resultsArray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        for(int i = 0; i + k - 1< n; i++) {
            int maxi = arr[i];
            bool ok = true;
            for(ll j = i + 1; j < i + k ; j++) {
                if(arr[j] - arr[j - 1] != 1) {
                    ans.push_back(-1);
                    ok = false;
                    break;
                }
                else {
                    if(arr[j] > maxi)
                        maxi = arr[j];
                }
            }
            if(ok) {
                ans.push_back(maxi);
            }
        }
        return ans;
    }
};