class Solution {
public:
    #define ll long long
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        ll n = nums1.size(), m = nums2.size();
        ll i = 0, j = 0;
        while(i < n and j < m) {
            auto p1 = nums1[i];
            auto p2 = nums2[j];
            if(p1[0] < p2[0]) {
                if(ans.empty()) {
                    ans.push_back(p1);
                    i++;
                    continue;
                }
                auto last = ans.back();
                if(last[0] == p1[0]) {
                    ans.pop_back();
                    p1[1] += last[1];
                    ans.push_back(p1);
                }
                else {
                    ans.push_back(p1);
                }
                i++;
            }
            else if(p2[0] < p1[0]) {
                if(ans.empty()) {
                    ans.push_back(p2);
                    j++;
                    continue;
                }
                auto last = ans.back();
                if(last[0] == p2[0]) {
                    ans.pop_back();
                    p2[1] += last[1];
                    ans.push_back(p2);
                }
                else {
                    ans.push_back(p2);
                }
                j++;
            }
            else {
                p1[1] += p2[1];
                if(ans.empty()) {
                    ans.push_back(p1);
                    i++;
                    j++;
                    continue;
                }
                auto last = ans.back();
                if(last[0] == p1[0]) {
                    ans.pop_back();
                    p1[1] += last[1];
                    ans.push_back(p1);
                }
                else {
                    ans.push_back(p1);
                }
                i++;
                j++;
            }
        }
        
        while(i < n) {
            auto p1 = nums1[i];
            ans.push_back(p1);
            i++;
        }
        while(j < m) {
            auto p2 = nums2[j];
            ans.push_back(p2);
            j++;
        }
        
        return ans;
    }
};