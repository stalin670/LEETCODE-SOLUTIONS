class Solution {
public:
/*
    By looking at the constraints, n <= 1e5
    we can have only O(n) / O(nlogn)

    so I thought about the binary search initially, 

    let's say we have a coordinate (3, 4)
    so for checking, if we have atleast 1 points in each 
    direction.

    so we can store the ordinate y in x array and abscissa x in y array
    in sorted manner.

    let's say in x line we have
              (3, 6)

    (1, 4)    (3, 4)    (6, 4)

              (3, 2)


    so here, to be in 1 line either for x = 3, or y = 4, 
    they should be present in x = 3 array and y = 4 array.
    And for checking, we can just check lower bound and upper bound.
*/
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, set<int>> mp_x, mp_y;
        for(auto u : buildings) {
            mp_x[u[0]].insert(u[1]);
            mp_y[u[1]].insert(u[0]);
        }
        int ans = 0;
        for(auto &vec : buildings) {
            int x = vec[0], y = vec[1];
            // cout << "x...." << endl;
            // for(auto el : mp_x[x]) cout << el << " ";
            // cout << endl;

            // cout << "y...." << endl;
            // for(auto el : mp_y[y]) cout << el << " ";
            // cout << endl;
            // cout << endl;

            if(mp_x[x].size() <= 2 or mp_y[y].size() <= 2) continue;
            int cnt = 0;
            // for x 
            int u = *mp_x[x].begin(), v = *mp_x[x].rbegin();
            if(u < y) cnt++;
            if(v > y) cnt++;

            // for y
            u = *mp_y[y].begin(), v = *mp_y[y].rbegin();
            if(u < x) cnt++;
            if(v > x) cnt++;

            if(cnt == 4) ans++;
        } 
        return ans;
    }
};