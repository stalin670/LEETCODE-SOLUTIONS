class Solution {
public:
    int countValidSelections(vector<int>& a) {
        int n = a.size(), ans = 0;

        auto checker = [&](auto vec) -> bool {
            set<int> st(vec.begin(), vec.end());
            return st.size() == 1 and *st.begin() == 0;
        };

        auto helper = [&](int idx) -> int {
            int possible = 0;
            // start moving right
            vector<int> vec = a;
            for(auto x : vec) cout << x << " ";
            cout << endl;
            int i = idx, dir = 1;
            while(i >= 0 and i < n) {
                if(vec[i] == 0) {
                    if(dir == 1) i++;
                    else i--;
                }
                else {
                    vec[i]--;
                    if(dir == 1) dir = -1;
                    else dir = 1;
                    if(dir == 1) i++;
                    else i--;
                }
            }
            if(checker(vec)) possible++;
            for(auto x : vec) cout << x << " ";
            cout << endl;
            // start moving left
            vec = a;
            for(auto x : vec) cout << x << " ";
            cout << endl;
            i = idx, dir = -1;
            while(i >= 0 and i < n) {
                if(vec[i] == 0) {
                    if(dir == 1) i++;
                    else i--;
                }
                else {
                    vec[i]--;
                    if(dir == 1) dir = -1;
                    else dir = 1;
                    if(dir == 1) i++;
                    else i--;
                }
            }
            if(checker(vec)) possible++;
            for(auto x : vec) cout << x << " ";
            cout << endl;
            return possible;
        };

        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                // cout << i << " " << helper(i) << endl;
                ans += helper(i);
            }
        }
        return ans;
    }
};