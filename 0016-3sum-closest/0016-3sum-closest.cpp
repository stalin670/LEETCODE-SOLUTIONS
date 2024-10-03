class Solution {
public:
    #define ll long long
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        ll closestSum = 1e15;
        ll n = arr.size();
        for(ll i = 0; i < n - 2; i++) {
            ll lb = i + 1, rb = n - 1;
            while(lb < rb) {
                ll currSum = arr[i] + arr[lb] + arr[rb];
                if(abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }
                if(currSum < target)
                    lb++;
                else if(currSum == target)
                    return currSum;
                else 
                    rb--;
            }
        }
        return closestSum;
    }
};