class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<char> arr(n,'*');
        string v="";
        for(int i=0;i<n;i++){
            if(s[i]!='A' && s[i]!='a' && s[i]!='e' && s[i]!='E' && s[i]!='i' && s[i]!='I' && s[i]!='o' && s[i]!='O' && s[i]!='u' && s[i]!='U'){
                arr[i]=s[i];
            }
            else v+=s[i];
        }

        sort(v.begin(),v.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='*'){
                arr[i]=v[j];
                j++;
            }
        }

        string ans="";

        for(auto it:arr) ans+=it;

        return ans;
    }
};