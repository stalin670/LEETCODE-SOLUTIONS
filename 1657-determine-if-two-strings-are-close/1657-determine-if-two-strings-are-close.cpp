class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> mp1,mp2;
        set<char> st;
        for(auto it:word1) st.insert(it);
        int curr=st.size();
        for(auto it:word2) st.insert(it);
        if(st.size()!=curr) return false;
        vector<int> need,have;
        for(auto it:word2) mp2[it]++;
        for(auto it:word1) mp1[it]++;
        for(auto it:mp2) need.push_back(it.second);
        for(auto it:mp1) have.push_back(it.second);
        sort(need.begin(),need.end());
        sort(have.begin(),have.end());
        if(need==have) return true;
        return false;
    }
};