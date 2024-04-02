#define ll long long
class Solution {
public:
    int longestDecomposition(string s) {
        ll n = s.size();
        vector<vector<string>> vs(n + 1, vector<string> (n + 1));
        for(ll i = n / 2; i < n; i++) {
            string t = "";
            for(ll j = i; j < n; j++) {
                t += s[j];
                vs[i][j] = t;
            }
        }
        
        ll ans = 0;
        ll i = 0, j = n - 1;
        ll last_brake = n - 1;
        string left = "", right = "";
        while(i <= j) {
            left += s[i];
            right = vs[j][last_brake];
            if(left == right and i != j) {
                ans += 2;
                left = "";
                last_brake = j - 1;
                i++;
                j--;
            }
            else if(i == j || i + 1 == j) {
                ans++;
                break;
            }
            else {
                i++;
                j--;
            }
        }
        return ans;
    }
};