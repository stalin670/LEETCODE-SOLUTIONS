class Solution {
public:
    #define ll long long
    
    ll helper_function(ll ind, ll firstOk, vector<int>& arr, vector<int> & brr, vector<vector<ll>> & dp, ll n) {
        if(ind >= n)
            return 0;
        
        if(ind == n - 1) {
            if(firstOk)
                return arr[ind];
            else 
                return brr[ind];
        }
        
        if(dp[ind][firstOk] != -1)
            return dp[ind][firstOk];
        
        ll max_energy = 0;
        if(firstOk) {
            max_energy = max(helper_function(ind + 1, firstOk, arr, brr, dp, n) , 
                              helper_function(ind + 2, 1 - firstOk, arr, brr, dp, n)) + arr[ind];
        }
        else {
            max_energy = max(helper_function(ind + 1, firstOk, arr, brr, dp, n) , 
                              helper_function(ind + 2, 1 - firstOk, arr, brr, dp, n)) + brr[ind];
        }
        
        return dp[ind][firstOk] = max_energy;
    }
    
    long long maxEnergyBoost(vector<int>& arr, vector<int>& brr) {
        ll n = arr.size();
        vector<vector<ll>> dp1(n + 1, vector<ll>(2, -1));
        ll max1 = helper_function(0, 1, arr, brr, dp1, n);
        vector<vector<ll>> dp2(n + 1, vector<ll>(2, -1));
        ll max2 = helper_function(0, 0, arr, brr, dp2, n);
        
        return max(max1, max2);
    }
};