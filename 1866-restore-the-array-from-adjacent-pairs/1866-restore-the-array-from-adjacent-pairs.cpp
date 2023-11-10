class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &mp, unordered_set<int> &st,vector<int>&ans){
            if(st.find(node)!=st.end()) return;
            st.insert(node);
            ans.push_back(node);
            for(auto it:mp[node]){
                dfs(it,mp,st,ans);
            }
        }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        for(auto it:adjacentPairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        int firstElement;
        for(auto it:mp){
            if(it.second.size()==1){
                firstElement=it.first;
                break;
            }
        }

        unordered_set<int> vis;
        vector<int> ans;
        dfs(firstElement,mp,vis,ans);
        return ans;
    }
};