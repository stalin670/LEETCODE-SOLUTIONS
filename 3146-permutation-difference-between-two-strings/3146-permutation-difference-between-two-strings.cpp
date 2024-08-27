class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> mp;
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        for(int i = 0; i < s.size(); i++) {
            ans += abs(mp[t[i]] - i);
        }
        return ans;
    }
};