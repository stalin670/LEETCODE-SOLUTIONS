class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> a;
        for(auto str : bank) {
            int cnt_ones = count(str.begin(), str.end(), '1');
            if(cnt_ones >= 1) a.push_back(cnt_ones);
        }
        int ans = 0;
        if(a.size() <= 1) return 0;
        for(int i = 1; i < a.size(); i++) {
            ans += a[i] * a[i - 1];
        }
        return ans;
    }
};