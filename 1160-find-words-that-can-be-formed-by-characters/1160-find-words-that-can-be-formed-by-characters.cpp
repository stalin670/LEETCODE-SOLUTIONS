class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> mp;
        for(auto it:chars) mp[it]++;
        int ans=0;
        for(int i=0;i<words.size();i++){
            map<char,int> t;
            t=mp;
            bool ok=1;
            for(auto it:words[i]){
                if(t[it]==0){
                    ok=0;
                    break;
                }
                else{
                    t[it]--;
                }
            }
            if(ok) ans+=words[i].size();
        }
        return ans;
    }
};