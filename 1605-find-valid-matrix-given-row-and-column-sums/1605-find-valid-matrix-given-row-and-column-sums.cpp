class Solution {
public:
    #define ll long long
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        ll n = rowSum.size(), m = colSum.size();
        vector<vector<int>> arr(n, vector<int> (m , 0));
        ll i = n - 1, j = m - 1;
        while(i >= 0 and j >= 0) {
            if(rowSum[i] < colSum[j]) {
                arr[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                i--;
            }
            else {
                arr[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                j--;
            }
        }
        
        return arr;
    }
};