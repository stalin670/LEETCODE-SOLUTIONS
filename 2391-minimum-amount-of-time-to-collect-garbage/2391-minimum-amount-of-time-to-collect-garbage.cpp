class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        int n=garbage.size();
        int x=0,y=0,z=0;
        for(int i=0;i<n;i++){
            string s=garbage[i];
            for(int j=0;j<s.size();j++){
                if(s[j]=='G'){
                    ans++;
                    z=i;
                }
                if(s[j]=='M'){
                    ans++;
                    x=i;
                }
                if(s[j]=='P') {
                    ans++;
                    y=i;
                }
            }
        }
        for(int i=0;i<x;i++){
            ans+=travel[i];
        }
        for(int i=0;i<z;i++){
            ans+=travel[i];
        }
        for(int i=0;i<y;i++){
            ans+=travel[i];
        }
        return ans;
    }
};