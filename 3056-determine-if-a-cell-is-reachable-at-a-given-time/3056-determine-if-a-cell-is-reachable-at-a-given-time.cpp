class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(sx-fx);
        int y=abs(sy-fy);
        int total = abs(x-y) + min(x,y);

        if(total==0){
            if(t!=1) return true;
            return false;
        }

        if(t>=total) return true;
        return false;
    }
};