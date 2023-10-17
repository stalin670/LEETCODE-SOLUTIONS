class Solution {
public:
    int countSegments(string s) {
        if(s.size()==0) return 0;
        int ans=0;
        string x="";
        for(auto it:s){
            if(it==' '){
                if(x.size()){
                    ans++;
                    x="";
                }
            }
            else x+=it;
        }
        if(x.size()) ans++;
        return ans;
    }
};