class Solution {
public:
    double helper(int x1, int y1, int x2, int y2, int x3, int y3) {
        int prod = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        double area = (double) prod / 2.0;
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    double area = helper(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                    if(area > ans)
                        ans = area;
                }
            }
        }
        return ans;
    }
};