class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans=0,maxi=INT_MIN,n=points.size();
        sort(points.begin(),points.end());
        for(int i=0;i<n-1;i++){
            int x=points[i][0];
            int y=points[i+1][0];
            int z=abs(x-y);
            if(z>maxi) maxi=z;
        }
        return maxi;
    }
};