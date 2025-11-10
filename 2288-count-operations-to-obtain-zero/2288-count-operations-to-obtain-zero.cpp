class Solution {
public:
    int countOperations(int x, int y) {
        if(x > y) swap(x, y);
        int ans = 0;
        while(x > 0 and y > 0) {
            y -= x;
            ans++;
            if(x > y) swap(x, y);
        }
        return ans;
    }
};