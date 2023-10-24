class Solution {
public:
    bool checkPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void f(int i,int n,string& s, vector<string> &temp, vector<vector<string>>& ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        for(int j=i;j<n;j++){
            if(checkPalindrome(i,j,s)){
                string x=s.substr(i,j-i+1);
                temp.push_back(x);
                f(j+1,n,s,temp,ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        f(0,n,s,temp,ans);

        return ans;
    }
};