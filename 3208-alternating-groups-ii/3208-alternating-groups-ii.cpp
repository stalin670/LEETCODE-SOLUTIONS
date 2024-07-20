class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int j = 0; j < k - 1; j++)
            colors.push_back(colors[j]);
        int ans = 0;
        int n = colors.size();
        vector<int> dp(n,1);
        for(int i = 1; i < n; i++)
        {
            if(colors[i-1] != colors[i])
                dp[i] = dp[i-1] + 1;
            
            if(i >= k-1 && dp[i] >= k)
                ans++;
        }
        return ans;
    }
};