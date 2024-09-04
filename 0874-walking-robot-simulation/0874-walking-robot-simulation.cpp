class Solution {
public:
    #define ll long long
    int robotSim(vector<int>& arr, vector<vector<int>>& obstacles) {
        map<string, ll> mp;
        for(auto &it : obstacles) {
            string str = to_string(it[0]) + "+" + to_string(it[1]);
            mp[str]++;
        }
        
        // for(auto &it : mp) {
        //     sort(it.second.begin(), it.second.end());
        // }
        
        pair<ll, ll> p = {0, 0};
        ll dir = 0;
        ll max_ans = LLONG_MIN;
        for(ll i = 0; i < arr.size(); i++) {
            if(arr[i] > 0) {
                ll k = arr[i];
                if(dir == 0) {
                    for(ll j = 1; j <= k; j++) {
                        string str = to_string(p.first) + "+" + to_string(p.second + 1);
                        if(mp.find(str) != mp.end())
                            break;
                        p.second++;
                    }
                }
                else if(dir == 1) {
                    for(ll j = 1; j <= k; j++) {
                        string str = to_string(p.first + 1) + "+" + to_string(p.second);
                        if(mp.find(str) != mp.end())
                            break;
                        p.first++;
                    }
                }
                else if(dir == 2) {
                    for(ll j = 1; j <= k; j++) {
                        string str = to_string(p.first) + "+" + to_string(p.second - 1);
                        if(mp.find(str) != mp.end())
                            break;
                        p.second--;
                    }
                }
                else {
                    for(ll j = 1; j <= k; j++) {
                        string str = to_string(p.first - 1) + "+" + to_string(p.second);
                        if(mp.find(str) != mp.end())
                            break;
                        p.first--;
                    }
                }
            }
            else if(arr[i] == -1) {
                dir = (dir + 1) % 4;
            }
            else {
                dir--;
                if(dir == -1) {
                    dir = 3;
                }
            }
            
            cout << p.first << " " << p.second << endl;
            ll max_dist = (abs(p.first) * abs(p.first));
            max_dist += (abs(p.second) * abs(p.second));
            
            max_ans = max(max_ans, max_dist);
        }
        
        cout << p.first << " " << p.second << endl;
        
        
        
        return max_ans;
    }
};