int dist[50][50][50][50];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void BFS(int stx, int sty) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{stx, sty}, 0});
    dist[stx][sty][stx][sty] = 0;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nyx = x + dx[i];
            int nyy = y + dy[i];
            if(nyx >= 0 and nyy >= 0 and nyx < 50 and nyy < 50 and dist[stx][sty][nyx][nyy] == -1) {
                dist[stx][sty][nyx][nyy] = d + 1;
                q.push({{nyx, nyy}, d + 1});
            }
        }
    }
}

void preCompute() {
    static bool done = false;
    if(done)
        return;
    memset(dist, -1, sizeof(dist));
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            if(dist[i][j][i][j] == -1) {
                BFS(i, j);
            }
        }
    }
    done = true;
}

class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int helper_function(int curr, int mask, int turn, vector<vector<int>>& positions) {
        int n = positions.size();
        if(mask == (1 << n) - 1)
            return 0;
        
        if(dp[curr][mask][turn] != -1)
            return dp[curr][mask][turn];
        
        int x = positions[curr][0];
        int y = positions[curr][1];
        int ans;
        
        if(!turn) {
            ans = INT_MIN;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i))
                    continue;
                int pawnX = positions[i][0];
                int pawnY = positions[i][1];
                int d = dist[x][y][pawnX][pawnY];
                
                ans = max(ans, d + helper_function(i, mask | (1 << i), !turn, positions));
            }
        }
        else {
            ans = INT_MAX;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i))
                    continue;
                int pawnX = positions[i][0];
                int pawnY = positions[i][1];
                int d = dist[x][y][pawnX][pawnY];
                
                ans = min(ans, d + helper_function(i, mask | (1 << i), !turn, positions));
            }
        }
        
        return dp[curr][mask][turn] = ans;
    }
    
    void checker() {
        for(int i = 0; i < 50; i++) {
            for(int j = 0; j < 50; j++) {
                for(int p = 0; p < 50; p++) {
                    for(int q = 0; q < 50; q++) {
                        cout << dist[i][j][p][q] << " ";
                    }
                }
                cout << endl;
            }
        }
    }
    
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx, ky});
        preCompute();
        // checker();
        int n = positions.size();
        dp.resize(n, vector<vector<int>>(1 << n, vector<int>(2,-1)));
        
        return helper_function(n-1, (1<<(n-1)), 0, positions);
    }
};