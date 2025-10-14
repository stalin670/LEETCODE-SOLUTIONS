class Solution {
public:
    bool checker(vector<int>& a, int start, int end) {
        for(int i = start + 1; i <= end; i++) {
            if(a[i] <= a[i - 1])
                return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& a, int k) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            int start1 = i, end1 = i + k - 1;
            int start2 = i + k, end2 = start2 + k - 1;
            if(end1 < n and end2 < n) {
                if(checker(a, start1, end1) and checker(a, start2, end2)) {
                    return true;
                }
            }
        }
        return false;
    }
};