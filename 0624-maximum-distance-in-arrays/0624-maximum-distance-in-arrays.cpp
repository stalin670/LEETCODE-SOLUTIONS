class Solution {
public:
    #define ll long long
    int maxDistance(vector<vector<int>>& arrays) {
        ll n = arrays.size();
        vector<pair<ll, ll>> arr;
        for(auto &it : arrays)
            if(it.size() == 1) 
                arr.push_back({it[0], it[0]});
            else
                arr.push_back({it[0], it[it.size() - 1]});
        
        sort(arr.begin(), arr.end());
        ll max_dist_1 = 0, max_dist_2 = 0;
        for(ll i = 1; i < n; i++) {
            max_dist_1 = max(max_dist_1, abs(arr[0].first - arr[i].second));
            max_dist_1 = max(max_dist_1, abs(arr[0].first - arr[i].first));
            max_dist_2 = max(max_dist_2, abs(arr[0].second - arr[i].second));
            max_dist_2 = max(max_dist_2, abs(arr[0].second - arr[i].first));
        }
        return max(max_dist_1, max_dist_2);
    }
};