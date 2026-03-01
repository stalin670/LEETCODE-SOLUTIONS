class Solution {
public:
    string trimTrailingVowels(string s) {
        string v = "aeiou";
        while(!s.empty() and v.find(s.back()) != string::npos) {
            s.pop_back();
        }
        return s;
    }
};