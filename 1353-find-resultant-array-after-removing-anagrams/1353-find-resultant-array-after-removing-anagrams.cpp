class Solution {
public:
    bool checkAnagrams(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for(int i = 0; i < words.size(); i++) {
            if(ans.empty()) ans.push_back(words[i]);
            else {
                string s = words[i];
                string t = ans.back();
                if(checkAnagrams(s, t)) {
                    continue;
                }
                else {
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};