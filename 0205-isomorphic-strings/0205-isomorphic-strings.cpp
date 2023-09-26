class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> cunt1;
        unordered_map<char, char> cunt2;

        for (int i = 0; i < s.size(); ++i) {
            if (cunt1[s[i]] == 0){ 
                cunt1[s[i]] = t[i];
            }

            else if (cunt1[s[i]] != t[i]) 
            return false;

            if (cunt2[t[i]] == 0) {
                cunt2[t[i]] = s[i];
            }
            else if (cunt2[t[i]] != s[i]) 
            return false;
        }

        return true;
    }
};