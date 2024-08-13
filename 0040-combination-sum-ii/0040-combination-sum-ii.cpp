class Solution {
public:
    vector<vector<int>> ans;
    
    void func(int ind, int target, vector<int>& arr, vector<int>& temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        
        if(target < 0)
            return;
        
        for(int i = ind ; i < arr.size(); i++) {
            if(i > ind and arr[i] == arr[i - 1])
                continue;
            if(arr[ind] > target) 
                break;
            temp.push_back(arr[i]);
            func(i + 1, target - arr[i], arr, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        func(0, target, candidates, temp);
        return ans;
    }
};