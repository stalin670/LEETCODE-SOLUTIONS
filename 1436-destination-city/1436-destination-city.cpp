class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> mp;
        string ans;
        for(int i=0;i<size(paths);i++){
            mp[paths[i][0]]++;
            mp[paths[i][1]]++;
        }
        for(auto it:mp){
            if(it.second==1){
                for(int i=0;i<size(paths);i++){
                    if(paths[i][1]==it.first){
                        ans=it.first;
                    }
                }
            }
        }
        return ans;
    }
};