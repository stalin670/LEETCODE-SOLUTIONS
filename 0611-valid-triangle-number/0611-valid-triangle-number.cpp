class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int k = n - 1; k > 1; k--) {
            int i = 0, j = k - 1;
            while(i < j) {
                int sum = nums[i] + nums[j];
                if(sum > nums[k]) {
                    ans += j - i;
                    j--;
                }
                else i++;
            }
        }
        return ans;
    }
};