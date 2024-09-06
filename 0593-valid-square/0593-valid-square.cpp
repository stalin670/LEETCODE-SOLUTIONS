class Solution {
public:
    #define ll long long
    ll dist(pair<ll, ll>& p1, pair<ll, ll>& p2) {
        ll x = abs(p1.first - p2.first);
        ll y = abs(p1.second - p2.second);
        x *= x;
        y *= y;
        return x + y;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<ll> st;
        set<pair<ll, ll>> stt;
        vector<pair<ll, ll>> arr;
        arr.push_back({p1[0], p1[1]});
        arr.push_back({p2[0], p2[1]});
        arr.push_back({p3[0], p3[1]});
        arr.push_back({p4[0], p4[1]});
        
        for(auto it : arr)
            stt.insert(it);
        
        if(stt.size() != 4)
            return false;
        
        for(ll i = 0; i < 4; i++) {
            for(ll j = i + 1; j < 4; j++) {
                ll distance = dist(arr[i], arr[j]);
                st.insert(distance);
            }
        }
        ll sz = st.size();
        if(sz == 2)
            return true;
        return false;
    }
};