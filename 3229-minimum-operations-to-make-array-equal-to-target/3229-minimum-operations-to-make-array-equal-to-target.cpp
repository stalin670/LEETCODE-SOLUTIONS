class Solution {
public:
    #define ll long long
    long long minimumOperations(vector<int>& arr, vector<int>& target) {
        ll n = arr.size();
        for(ll i = 0; i < n; i++) 
            arr[i] = target[i] - arr[i];
        
        ll ans = 0;
        ll tempOp = abs(arr[0]);
        bool positive = (arr[0] >= 0);
        
        for(ll i = 1; i < n; i++) {
            if(arr[i] > 0) {
                 if(positive) {
                     ll diff = arr[i] - arr[i - 1];
                     if(diff > 0)
                         tempOp += diff;
                 }
                else {
                    ans += tempOp;
                    tempOp = arr[i];
                    positive = true;
                }
            }
            else if(arr[i] == 0) {
                ans += tempOp;
                tempOp = 0;
                if(!positive) {
                    positive = true;
                }
            }
            else {
                if(!positive) {
                    ll diff = abs(arr[i]) - abs(arr[i - 1]);
                    if(diff > 0)
                        tempOp += diff;
                }
                else {
                    ans += tempOp;
                    tempOp = abs(arr[i]);
                    positive = false;
                }
            }
        }
        if(tempOp)
            ans += tempOp;
        return ans;
    }
};