class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> div(maxi + 1, 1);
        vector<int> countDiv(maxi + 1, 1);

        for(int i = 2; i <= maxi; i++) {
            for(int j = i; j <= maxi; j += i) {
                div[j] += i;
                countDiv[j]++;
            }
        }

        int ans = 0;
        for(auto x : nums) {
            if(countDiv[x] == 4) {
                ans += div[x];
            }
        }
        return ans;
    }
};