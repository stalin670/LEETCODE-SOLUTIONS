class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string ans="";
        int n=arr.size();
        int minLen=200;
        for(int i=0;i<n;i++){
            int x=arr[i].size();
            minLen=min(minLen,x);
        }
        
        for(int i=0;i<minLen;i++){
            for(int j=0;j<n-1;j++){
                if(arr[j][i]!=arr[j+1][i]){
                    return ans;
                }
            }
            ans+=arr[0][i];
        }
        
        return ans;
    }
};