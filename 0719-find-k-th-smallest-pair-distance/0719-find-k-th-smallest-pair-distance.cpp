#define ll long long
class Solution {
public:
    ll check(vector<int> nums, int n, int mb) {
        ll pairs = 0;
        ll j = 0;
        for(ll i=0; i<n; i++) {
            while(j < n and nums[j] - nums[i] <= mb)
                j++;
            pairs += j - i -1;
        }
        
        return pairs;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        ll n = nums.size();
        
        ll lb = -1, rb = 1e6, ans;
        
        while(lb <= rb) {
            ll mb = lb + (rb - lb) / 2;
            
            ll total_pairs = check(nums, n, mb);
            if(total_pairs >= k) {
                ans = mb;
                rb = mb -1 ;
            }
            else
                lb = mb + 1;
        }
        
        return ans;
    }
};