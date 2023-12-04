class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int digit=0;
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] and num[i+1]==num[i+2]){
                int d=num[i]-'0';
                string s="";
                s+=num[i];
                s+=num[i];
                s+=num[i];
                if(d>=digit){
                    ans=s;
                    digit=d;
                }
            }
        }
        return ans;
    }
};