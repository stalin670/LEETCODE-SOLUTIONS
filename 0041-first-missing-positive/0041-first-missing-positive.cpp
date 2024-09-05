class Solution {
public:
    #define ll long long
    int firstMissingPositive(vector<int>& arr) {
        ll n = arr.size();
        bool have_one = false;
        // Mark those value 1 which are negatives or greater than n
        for(ll i = 0; i < n; i++) {
            if(arr[i] == 1) {
                have_one = true;
            }
            if(arr[i] <= 0 || arr[i] > n) {
                arr[i] = 1;
            }
        }
        // If 1 is not present in the array then its the answer
        if(!have_one)
            return 1;
        
        // Traverse the array and mark the current val as an index negative
        for(ll i = 0; i < n; i++) {
            if(arr[abs(arr[i]) - 1] > 0) {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            }
        }
        
        // Traverse the array and Check which index val is positive , that is the answer
        for(ll i = 0; i < n; i++) {
            if(arr[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};