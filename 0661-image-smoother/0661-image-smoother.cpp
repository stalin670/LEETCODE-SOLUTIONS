class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s=0,c=0;
                for(int k=max(0,i-1);k<min(n,i+2);k++){
                    for(int p=max(0,j-1);p<min(m,j+2);p++){
                        s+=img[k][p];
                        c++;
                    }
                }
                ans[i][j]=s/c;
            }
        }
        return ans;
    }
};