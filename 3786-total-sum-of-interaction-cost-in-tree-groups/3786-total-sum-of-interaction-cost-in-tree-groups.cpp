#define ll long long
class Solution {
public:
/*
    1 <= n <= 1e5
    1 <= group[i] <= 20

    expected soln = nlogn or n * g <= 1e7

    for each pair which are in same group, we have to count
    the number of edges between them, that't it.

    we can write a brute forces solution in O(n * n) but TLE.

    ??

    instead of that, we can run dfs on nodes, but for each
    edge, we can check for how many pairs it contributed till 
    now.

    Simple Observation:

    lets suppose we have

    g g g   --------- g g g g g

    here left side 3 nodes which have same group g
    and right side 5 nodes which have same group g

    so total number of contribution by this edge is 
    3 * 5

    so we are dealing with the edges / components / subtree
    specifically.

    LOGIC ????

    so we'll do basic DFS starting from node 0.
    and we will track the number of g for all nodes in vectors

    and after that we'll try to check if there is any other nodes
    out of this subtree such that we've the same group g for them

    so till this point, we'll directly add the total contribution of 
    that edge to out ans.

    so this have TC ~ O(n * g) ~ 1e5 * 20 = 2e6

    This wil definitely works!!
*/
    vector<vector<int>> adj;
    vector<int> ar;
    vector<int> groupCnt;
    ll ans = 0;

    vector<ll> dfs(int node, int par) {
        vector<ll> res(21, 0);
        res[ar[node]]++;

        for(auto child : adj[node]) {
            if(child == par)
                continue;
            vector<ll> comp = dfs(child, node);
            for(int i = 1; i < 21; i++) {
                if(comp[i] <= 0) continue;
                res[i] += comp[i];
                int in = comp[i];
                int out = groupCnt[i] - comp[i];
                ans += (ll)in * (ll)out;
            }
        }
        return res;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        ar = group;
        groupCnt.assign(21, 0);
        adj.assign(n, vector<int>());
        for(auto g : group) {
            groupCnt[g]++;
        }
        for(auto vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        return ans;
    }
};