class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=-1,maxii=-1;
        for(auto it:nums){
            if(maxi==-1){
                maxi=it;
            }
            else if(it>=maxi){
                maxii=maxi;
                maxi=it;
            }
            else maxii=max(maxii,it);
        }
        return (maxi-1)*(maxii-1);
    }
};