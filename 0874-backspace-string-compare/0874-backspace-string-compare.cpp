class Solution {
public:
    int Validindex(string str, int end) {
        int backspace_count = 0;
        while (end >= 0) {
            if (str[end] == '#') {
                backspace_count++;
            } else if (backspace_count > 0) {
                backspace_count--;
            } else {
                break;
            }
            end--;
        }
        return end;
    }    

    bool backspaceCompare(string s, string t) {
        int ss = s.length() - 1;
        int tt = t.length() - 1;

        while (ss >= 0 || tt >= 0) {
            ss = Validindex(s, ss);
            tt = Validindex(t, tt);

            if (ss < 0 && tt < 0) {
                return true;
            }
            if (ss < 0 || tt < 0) {
                return false;
            } else if (s[ss] != t[tt]) {
                return false;
            }

            ss--;
            tt--;
        }

        return true;
    }
};