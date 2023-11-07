class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        int ans=0;
        vector<int> time(n);
        for (int i = 0; i < n; i++) time[i] = (dist[i] + speed[i] - 1) / speed[i];
        sort(time.begin(), time.end());

        int curr_time = 0;
        for (const int& t : time) {
            if (curr_time >= t) return ans;
            ans++;
            curr_time++;
        }
        return ans;
    }
};