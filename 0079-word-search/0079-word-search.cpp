#define ll long long
class Solution {
public:
    bool dfs(ll i, ll j, ll pos, vector<vector<char>>& board, string word, vector<vector<ll>>& vis, ll n, ll m) {
        if(pos == word.size())
            return true;
        
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        if(board[i][j] != word[pos] || vis[i][j])
            return false;
        
        bool ok = false;
        vis[i][j] = true;
        ok |= dfs(i + 1, j, pos + 1, board, word, vis, n, m);
        ok |= dfs(i - 1, j, pos + 1, board, word, vis, n, m);
        ok |= dfs(i, j - 1, pos + 1, board, word, vis, n, m);
        ok |= dfs(i, j + 1, pos + 1, board, word, vis, n, m);
        vis[i][j] = false;
        return ok;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        ll n = board.size();
        ll m = board[0].size();
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<ll>> vis(n, vector<ll> (m, 0));
                    bool check = dfs(i, j, 0, board, word, vis, n, m);
                    if(check == true)
                        return true;
                }
            }
        }
        return false;            
    }
};