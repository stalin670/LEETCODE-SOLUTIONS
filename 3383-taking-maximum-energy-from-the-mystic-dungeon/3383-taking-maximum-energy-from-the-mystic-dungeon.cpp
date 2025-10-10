class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            if(i + k >= n) dp[i] += energy[i];
            else dp[i] = dp[i + k] + energy[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};