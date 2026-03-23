#define ll long long
class Solution {
public:
    bool uniformArray(vector<int>& a) {
        ll mini = *min_element(a.begin(), a.end());
        ll odd = count_if(a.begin(), a.end(), [&](int x) {
            return x % 2 == 1;
        });
        if(odd > 0 and mini % 2 == 0) return false;
        return true;
    }
};