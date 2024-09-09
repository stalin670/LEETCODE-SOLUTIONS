class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        ll target = t;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int a = j + 1, b = n - 1;
                while(a < b) {
                    ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[a] + (ll)nums[b];
                    if(sum == target) {
                        st.insert({nums[i], nums[j], nums[a], nums[b]});
                        a++;
                        b--;
                    }
                    else if(sum > target) {
                        b--;
                    }
                    else {
                        a++;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it : st)
            ans.push_back(it);
        return ans;
    }
};