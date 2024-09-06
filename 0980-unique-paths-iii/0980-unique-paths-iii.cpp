class Solution {
public:
    #define ll long long
    ll helper_function(ll i, ll j, ll total, ll covered, vector<vector<int>>& grid, vector<vector<ll>>& vis) {
        ll n = grid.size(), m = grid[0].size();
        if(i >= n || i < 0 || j >= m || j < 0)
            return 0;
        if(grid[i][j] == -1 || vis[i][j] == 1)
            return 0;
        if(grid[i][j] == 2 and covered + 1 == total)
            return 1;
        
        vis[i][j] = 1;
        covered++;
        ll up = helper_function(i - 1, j, total, covered, grid, vis);
        ll right = helper_function(i, j + 1, total, covered, grid, vis);
        ll down = helper_function(i + 1, j, total, covered, grid, vis);
        ll left = helper_function(i, j - 1, total, covered, grid, vis);
        
        vis[i][j] = 0;
        covered--;
        return (up + right + down + left);
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        ll n = grid.size(), m = grid[0].size();
        ll square = 0;
        ll stx, sty;
        for(ll i = 0; i < n; i++) 
            for(ll j = 0; j < m; j++) {
                if(grid[i][j] != -1)
                    square++;
                if(grid[i][j] == 1) {
                    stx = i, sty = j;
                }
            }
        
        vector<vector<ll>> vis(n + 1, vector<ll> (m + 1, 0));
        ll covered = 0;
        ll ways = helper_function(stx, sty, square, covered, grid, vis);
        return ways;
    }
};