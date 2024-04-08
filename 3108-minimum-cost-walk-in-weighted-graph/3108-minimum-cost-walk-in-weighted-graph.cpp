#define ll long long
class Solution {
public:
    void dfs(ll node, vector<ll> adj[], vector<ll> & vis, ll curr, vector<ll> & c) {
        vis[node] = 1;
        c[node] = curr;
        for(auto child : adj[node]) {
            if(!vis[child])
                dfs(child, adj, vis, curr, c);
        }
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<ll> adj[n + 1];
        for(ll i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<ll> vis(n + 1, 0);
        vector<ll> component(n);
        ll curr = 1;
        for(ll i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, curr, component);
            }
            curr++;
        }
        ll mxx = pow(2, 20) - 1;
        vector<ll> edge_score(curr, mxx);
        for(ll i = 0; i < edges.size(); i++) {
            edge_score[component[edges[i][0]]] &= edges[i][2];
            edge_score[component[edges[i][1]]] &= edges[i][2];
        }
        
        vector<int> ans;
        for(ll i = 0; i < query.size(); i++) {
            if(query[i][0] == query[i][1]) 
                ans.push_back(0);
            else if(component[query[i][0]] != component[query[i][1]])
                ans.push_back(-1);
            else
                ans.push_back(edge_score[component[query[i][0]]]);
        }
        return ans;
    }
};