class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int> m;
        int n=allowed.size();

        for(int i=0;i<n;i++){
            m[allowed[i]]++;
        }

        int ms=words.size();
        int ans=0;
        for(int i=0;i<ms;i++){
            bool ok=true;
            for(auto it : words[i]){
                if(m[it]==0) ok=false;
            }

            if(ok) ans++;
        }

        return ans;
    }
};