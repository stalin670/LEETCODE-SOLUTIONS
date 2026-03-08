class Solution {
public:
    bool checkOnesSegment(string s) {
        vector<int> a;
        int cnt = 0;
        for(auto ch : s) {
            if(ch == '1') {
                cnt++;
            }
            else {
                if(cnt > 0) a.push_back(cnt);
                cnt = 0;
            }
        }
        if(cnt > 0) a.push_back(cnt);
        return a.size() == 1;
    }
};