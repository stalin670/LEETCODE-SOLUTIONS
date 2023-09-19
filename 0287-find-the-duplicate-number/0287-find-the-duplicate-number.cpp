class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto &x : nums) {
            if (hash.count(x))
                return x;
            hash.insert(x);
        }
        return -1;
        
    }
};