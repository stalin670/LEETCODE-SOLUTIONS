class Solution {
public:
    int findMinDifference(vector<string>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int firstmin = stoi(arr[0].substr(0, 2)) * 60 + stoi(arr[0].substr(3, 2)) + 24 * 60;
        int lastmin = stoi(arr[n - 1].substr(0, 2)) * 60 + stoi(arr[n - 1].substr(3, 2));
        int ans = abs(firstmin - lastmin);
        
        for(int i = 1; i < n; i++) {
            int prevmin = stoi(arr[i - 1].substr(0, 2)) * 60 + stoi(arr[i - 1].substr(3, 2));
            int currmin = stoi(arr[i].substr(0, 2)) * 60 + stoi(arr[i].substr(3, 2));
            ans = min(ans, abs(prevmin - currmin));
        }
        // for(auto &it : arr)
        //     cout << it << " ";
        // cout << endl;
        
        cout << firstmin << " " << lastmin << endl;
        
        return ans;
    }
};