#define ll long long
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(ll i = 0; i <= 1; i++) {
            for(ll j = 0; j <= 1;  j++) {
                ll w = 0, b = 0;
                if(grid[i][j] == 'W')
                    w++;
                else 
                    b++;
                if(grid[i][j + 1] == 'W')
                    w++;
                else 
                    b++;
                if(grid[i + 1][j] == 'W')
                    w++;
                else 
                    b++;
                if(grid[i + 1][j + 1] == 'W')
                    w++;
                else 
                    b++;
                
                if(w >= 3 or b >= 3)
                    return true;
            }
        }
        return false;
    }
};