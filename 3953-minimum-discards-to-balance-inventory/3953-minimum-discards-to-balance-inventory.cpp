class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        map<int, queue<int>> q;
        int ans = 0, n = arrivals.size();
        for(int i = 0; i < n; i++) {
            while(!q[arrivals[i]].empty() and (q[arrivals[i]].front() + w <= i)) {
                q[arrivals[i]].pop();
            }
            if(q[arrivals[i]].size() < m) q[arrivals[i]].push(i);
            else ans++;
        }
        return ans;
    }
};