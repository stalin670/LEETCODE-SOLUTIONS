class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0, j = 1, n = arr.size();
        while(j < n) {
            while(j < n and arr[i] == arr[j])
                j++;
            if(j < n and arr[i] != arr[j]) {
                arr[i + 1] = arr[j];
                i++;
            }
        }
        return i + 1;
    }
};