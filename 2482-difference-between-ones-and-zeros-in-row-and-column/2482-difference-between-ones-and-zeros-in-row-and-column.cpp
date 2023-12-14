class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> OnesR(n),OnesC(m);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
            OnesR[i]=cnt;
        }
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1) cnt++;
            }
            OnesC[i]=cnt;
        }
        
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=OnesR[i]+OnesC[j]-(m-OnesR[i])-(n-OnesC[j]);                
            }
        }
        return ans;
    }
};