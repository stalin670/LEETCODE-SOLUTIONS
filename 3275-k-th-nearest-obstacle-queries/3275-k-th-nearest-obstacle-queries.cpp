class Solution {
public:
    #define ll long long
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<ll> pq;
        vector<int> ans(queries.size());
        for(ll i = 0; i < queries.size(); i++) {
            ll x = queries[i][0];
            ll y = queries[i][1];
            ll dist = abs(x) + abs(y);
            pq.push(dist);
            if(pq.size() > k) {
                pq.pop();
            }
            if(i + 1 >= k)
                ans[i] = pq.top();
            else 
                ans[i] = -1;
        }
        
        return ans;
    }
};