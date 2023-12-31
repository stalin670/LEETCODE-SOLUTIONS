class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,vector<int>> mp;
        int ans=0;
        bool ok=0;
        for(int i=0;i<s.size();i++){
            if(!mp[s[i]].empty()){
                int len=i-mp[s[i]][0]-1;
                ans=max(ans,len);
                ok=1;
            }
            mp[s[i]].push_back(i);
        }
        if(!ok) return -1;
        return ans;
    }
};