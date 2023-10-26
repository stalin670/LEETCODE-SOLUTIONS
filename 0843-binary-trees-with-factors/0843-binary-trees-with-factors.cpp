class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        if(arr.size()==1) return 1;

        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;

        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]] = 1;
        }

        for(int i = 1; i<arr.size(); i++){
            for(int j = 0; j<i && arr[j]<=sqrt(arr[i]); j++){
                if(arr[i] % arr[j] == 0 && mp.find(arr[i]/arr[j]) != mp.end()){
                    if(arr[i]/arr[j] == arr[j]){
                        mp[arr[i]] += (mp[arr[j]] * mp[arr[i]/arr[j]]); 
                    }
                    else{
                        mp[arr[i]] += (mp[arr[j]] * mp[arr[i]/arr[j]]) * 2; 
                    }
                }
            }
        }

        long long ans = 0;
        for(auto it: mp){
            ans+=it.second;
        }
        return ans%(1000000007);
    }
};