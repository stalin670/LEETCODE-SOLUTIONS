class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> vp;
        int n = names.size();
        for(int i = 0; i < n; i++) {
            vp.push_back({heights[i], names[i]});
        }
        sort(vp.rbegin(),vp.rend());
        for(int i = 0; i < n; i++) {
            names[i] = vp[i].second;
        }
        return names;
    }
};