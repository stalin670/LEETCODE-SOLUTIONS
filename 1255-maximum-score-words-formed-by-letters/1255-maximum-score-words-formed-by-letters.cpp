class Solution {
public:
    #define ll long long
    
    string numToBin(ll n, ll len) {
        string x = "";
        for (ll i = 1; i <= len; i++) {
            if (n) {
                ll last_digit = n % 2;
                n /= 2;
                if (last_digit)
                    x += '1';
                else
                    x += '0';
            }
            else {
                x += '0';
            }
        }
        reverse(x.begin(), x.end());
        return x;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ll max_ans = 0;
        ll n = words.size();
        map<ll, ll> freq;
        for(auto &ch : letters) {
            freq[ch - 'a']++;
        }
        
        for(ll i = 1; i < (1 << n);  i++) {
            string x = numToBin(i, n);
            map<ll, ll> dupl = freq;
            bool done = true;
            ll score_c = 0;
            for(ll j = 0; j < n; j++) {
                if(x[j] == '1') {
                    map<ll, ll> t;
                    for(auto &ch : words[j]) {
                        t[ch - 'a']++;
                    }
                    
                    for(auto &it : t) {
                        if(dupl.find(it.first) == dupl.end()) {
                            done = false;
                            break;        
                        }
                        if(it.second > dupl[it.first]) {
                            done = false;
                            break;
                        }
                        else {
                            score_c += (it.second * score[it.first]);
                            dupl[it.first] -= it.second;
                        }
                    }
                    
                    if(!done)
                        break;
                }
                else {
                    continue;
                }
            }
            if(done)
                max_ans = max(max_ans, score_c);
        }
        return max_ans;
    }
};