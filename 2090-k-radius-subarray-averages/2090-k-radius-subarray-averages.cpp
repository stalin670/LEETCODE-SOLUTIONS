#define ll long long
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        
        if(2*k+1 > n)
            return ans;
        
        ll sub_arr_sum = 0;
        for(int i=0; i<2*k; i++)
            sub_arr_sum += nums[i];
        
        for(int i=k; i+k<n; i++) {
            sub_arr_sum += nums[i+k];
            ans[i] = sub_arr_sum / (2*k+1);
            sub_arr_sum -= nums[i-k];
        }
        
        return ans;
    }
};