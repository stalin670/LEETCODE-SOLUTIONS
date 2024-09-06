class Solution {
public:
    #define ll long long
    vector<int> t = {0};
    void dfs(ll node, ll n, vector<ll> adj[], vector<vector<int>>& ans) {
        if(node == n - 1) {
            ans.push_back(t);
            return;
        }
        
        for(auto child : adj[node]) {
            t.push_back(child);
            dfs(child, n, adj, ans);
            t.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ll n = graph.size();
        vector<ll> adj[n];
        for(ll i = 0; i < n; i++) {
            for(auto &it : graph[i]) {
                adj[i].push_back(it);
            }
        }
        vector<vector<int>> ans;
        dfs(0, n, adj, ans);
        return ans;
    }
};