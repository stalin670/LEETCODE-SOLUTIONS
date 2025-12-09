class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int specialTriplets(vector<int>& a) {
        /*  
            3 <= n <= 1e5
            0 <= ai <= 1e5

            finding triplet such that
            i < j < k
            and 
            ai = aj * 2
            ak = aj * 2

            first we'll count all the elements
            and then count all element till index i
            so that we can get all aj * 2 before i and after
            i
        */

        ll ans = 0;
        map<ll, ll> freq;
        for(auto x : a) freq[x]++;

        map<ll, ll> cur;
        cur[a[0]]++;
        for(ll i = 1; i < a.size() - 1; i++) {
            ll need = a[i] * 2;
            if(cur.find(need) != cur.end() and freq.find(need) != freq.end()) {
                ll ways = (cur[need]) * (freq[need] - cur[need] - (a[i] == 0 ? 1 : 0));
                ans = (ans + ways) % mod;
                // cout << cur[need] << " " << freq[need] << endl;
            }
            cur[a[i]]++;
        }
        return ans;
    }
};