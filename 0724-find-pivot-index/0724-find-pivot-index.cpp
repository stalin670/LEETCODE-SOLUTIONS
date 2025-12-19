class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();
        int pref[n];
        int suff[n];

        pref[0] = arr[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + arr[i];
        }

        suff[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + arr[i];
        }

        if(n == 1) return 0;

        if(suff[1] == 0) return 0;

        for(int i = 1; i < n - 1; i++) {
            if(pref[i - 1] == suff[i + 1]) {
                return i;
            }
        }

        if(pref[n - 2] == 0) return n - 1;

        return -1;
    }
};