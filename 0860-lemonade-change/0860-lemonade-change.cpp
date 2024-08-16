class Solution {
public:
    #define ll long long
    bool lemonadeChange(vector<int>& bills) {
        map<ll, ll> mp;
        for(ll i = 0; i < bills.size(); i++) {
            ll x = bills[i];
            if(x == 5) {
                mp[x]++;
                continue;
            }
            if(x == 20) {
                if(mp.find(5) == mp.end())
                    return false;
                if(mp.find(10) == mp.end()) {
                    if(mp[5] >= 3) {
                        mp[5] -= 3;
                        if(mp[5] == 0)
                            mp.erase(5);
                    }   
                    else
                        return false;
                }
                else {
                    mp[10]--;
                    mp[5]--;  
                    if(mp[10] == 0)
                        mp.erase(10);
                    if(mp[5] == 0)
                        mp.erase(5);
                }
            }
            else {
                if(mp.find(5) == mp.end())
                    return false;
                mp[5]--;
                if(mp[5] == 0)
                   mp.erase(5);
            }
            mp[x]++;
        }
        return true;
    }
};