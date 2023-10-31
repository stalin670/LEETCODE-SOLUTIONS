class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());
        ans[0]=pref[0];
        int x=pref[0];
        for(int i=1;i<pref.size();i++){
            int curr=x^pref[i];
            x^=curr;
            ans[i]=curr;
        }
        return ans;
    }
};