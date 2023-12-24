class Solution {
public:
    int minOperations(string s) {
        int s1=0,s2=0;
        for(int i=0;i<s.size();i++){
            if(i%2){
                if(s[i]=='0') s1++;
            }else{
                if(s[i]=='1') s1++;
            }
            
            
            if(i%2){
                if(s[i]=='1') s2++;
            }else{
                if(s[i]=='0') s2++;
            }
        }
        return min(s1,s2);
    }
};