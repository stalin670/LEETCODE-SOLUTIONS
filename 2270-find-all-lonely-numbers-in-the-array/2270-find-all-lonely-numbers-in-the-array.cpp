class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=mp[nums[i]]+1;
        }

        vector<int> arr;

        for(auto it:nums){
            int prev=it-1;
            int next=it+1;
            if(mp[prev]==0 && mp[next]==0 && mp[it]==1){
                arr.push_back(it);
            }
        }

        return arr;
    }
};