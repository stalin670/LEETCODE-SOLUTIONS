class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        auto helper = [&](int k) -> bool {
            int cnt = 0;
            for(int i = 1; i + k < n; i++) {
                if(nums[i] > nums[i - 1] and nums[i + k] > nums[i + k - 1]) {
                    cnt++;
                }
                else cnt = 0;
                if(cnt == k - 1) break;
            }
            return cnt == k - 1;
        };

        int lb = 2, rb = n / 2, ans = 1;
        while(lb <= rb) {
            int mb = (lb + rb) >> 1;
            if(helper(mb)) {
                ans = mb;
                lb = mb + 1;
            }
            else {
                rb = mb - 1;
            }
        }
        return ans;
    }
};