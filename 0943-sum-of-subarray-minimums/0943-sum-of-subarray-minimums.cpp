#define ll long long
const int mod = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prvSmaller(n), nxtSmaller(n);
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() and arr[stk.top()] > arr[i]) {
                nxtSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            nxtSmaller[stk.top()] = n;
            stk.pop();
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() and arr[stk.top()] >= arr[i]) {
                prvSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            prvSmaller[stk.top()] = -1;
            stk.pop();
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            cout << prvSmaller[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << nxtSmaller[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            int left = i - prvSmaller[i];
            int right = nxtSmaller[i] - i;
            ll prod =  ((left * right % mod) * (ll)arr[i]) % mod;
            ans = (ans + prod) % mod;
            ans %= mod;
            // cout << arr[i] << " -> " << cnt << " m -> " << m << endl;
        }
        return ans;
    }
};