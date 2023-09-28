class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        // vector<int> ans;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2==0){
        //         ans.push_back(nums[i]);
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2==1){
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;
        int i=0,j=n-1;
        while(i<=j){
            if(nums[i]%2==1){
                swap(nums[i],nums[j--]);
            }
            else i++;
        }
        return nums;
    }
};