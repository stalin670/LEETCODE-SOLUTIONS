class Solution {
public:
    int countOfSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        set<char> v = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++) {
            int cons = 0;
            set<char> st;
            for(int j = i; j < n; j++) {
                if(cons > k)
                    break;
                if(v.find(s[j]) != v.end()) 
                    st.insert(s[j]);
                else
                    cons++;
                
                if(st.size() == 5 and cons == k)
                    ans++;
            }
        }
        return ans;
    }
};