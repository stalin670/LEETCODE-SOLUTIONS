class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<size(mat);i++){
            for(int j=0;j<size(mat[i]);j++){
                if(mat[i][j]==1){
                    int cnt=1;
                    for(int k=0;k<size(mat);k++){
                        if(mat[k][j]==1 and i!=k) cnt++;
                    }
                    for(int k=0;k<size(mat[i]);k++){
                        if(mat[i][k]==1 and j!=k) cnt++;
                    }
                    if(cnt==1) ans++;
                }
            }
        }
        return ans;
    }
};