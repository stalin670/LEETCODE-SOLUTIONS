class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<string> vec = {"1","22","122","333","1333","4444","14444","22333","55555","122333","155555","224444","666666","1224444"};
        vector<int> a;
        for(auto str : vec) {
            a.push_back(stoi(str));
            while(next_permutation(str.begin(), str.end())) {
                a.push_back(stoi(str));
            }
        }
        sort(a.begin(), a.end());
        return *upper_bound(a.begin(), a.end(), n);
    }
};