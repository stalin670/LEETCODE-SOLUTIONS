class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto &it : details)
            if((it[11] - '0') * 10 + (it[12] - '0') > 60)
                ans++;
        return ans;
    }
};