class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            arr[0][i]=matrix[0][i];
        }

        for(int i=0;i<n;i++){
            arr[i][0]=matrix[i][0];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0) continue;
                int up=arr[i-1][j];
                int left=arr[i][j-1];
                int diagonal=arr[i-1][j-1];
                int mini=min(up,min(left,diagonal));
                if(matrix[i][j]==1){
                    arr[i][j]=1+mini;
                }
                else{
                    arr[i][j]=0;
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
                ans+=arr[i][j];
            }
            cout<<endl;
        }
        cout<<endl;

        return ans;
    }
};