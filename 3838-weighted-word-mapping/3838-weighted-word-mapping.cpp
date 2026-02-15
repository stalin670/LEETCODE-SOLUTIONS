class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for(auto w: words) {
            int sum = 0;
            for(auto ch: w) {
                sum += weights[(ch - 'a')];
            }
            sum %= 26;
            int idx = 26 - sum - 1;
            ans += char(idx + 'a');
        }

        return ans;
    }
};