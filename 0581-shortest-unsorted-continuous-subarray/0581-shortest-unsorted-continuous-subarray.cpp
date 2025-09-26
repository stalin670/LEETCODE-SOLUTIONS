const int INF = 100000000;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        int i = 0, j = n - 1;
        while(i < n - 1 and a[i + 1] >= a[i])
            i++;
        if(i == n - 1)
            return 0;
        while(j >= 1 and a[j - 1] <= a[j])
            j--;
        int mini = INF, maxi = -INF;
        for(int k = i; k <= j; k++) {
            mini = min(mini, a[k]);
            maxi = max(maxi, a[k]);
        }
        while(i > 0 and a[i - 1] > mini)
            i--;
        while(j < n - 1 and a[j + 1] < maxi)
            j++;
        return j - i + 1;
    }
};