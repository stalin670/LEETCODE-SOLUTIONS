class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> left(26,-1),right(26,-1);
        for(int i=0;i<n;i++){
            int x=s[i]-'a';
            if(left[x]==-1) left[x]=i;
            right[x]=i;
        }

        int ans=0;
        vector<bool> count(26,0);

        for(int i=0;i<26;i++){
            if(left[i]==-1) continue;
            for(int j=0;j<26;j++) count[j]=0;
            for(int j=left[i]+1;j<right[i];j++){
                if(!count[s[j]-'a']){
                    ans++;
                    count[s[j]-'a']=1;
                }
            }
        }

        return ans;
    }
};