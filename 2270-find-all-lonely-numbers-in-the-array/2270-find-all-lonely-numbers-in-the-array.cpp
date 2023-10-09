class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;

        vector<int> arr;

        for(auto it:nums){
            int prev=it-1;
            int next=it+1;
            if(!mp[prev] and !mp[next] and mp[it]==1){
                arr.push_back(it);
            }
        }

        return arr;
    }
};