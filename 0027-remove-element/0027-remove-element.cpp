class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int j = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != val) {
                arr[j] = arr[i];
                j++;
            }
        }
        return j;
    }
};