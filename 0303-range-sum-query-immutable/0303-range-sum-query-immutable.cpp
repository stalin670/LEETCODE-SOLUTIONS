class NumArray {
public:
int pref[100000];
    NumArray(vector<int>& nums) {
        pref[0] = nums[0];
        for(int i = 1; i< nums.size(); i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return pref[right];
        return pref[right] - pref[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */