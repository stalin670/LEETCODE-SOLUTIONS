class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int sz=target.size();

        for(int i=0,x=1;i<sz;i++){
            while(target[i]>x){
                ans.push_back("Push");
                ans.push_back("Pop");
                x++;
            }
            ans.push_back("Push");
            x++;
        }
        return ans;
    }
};