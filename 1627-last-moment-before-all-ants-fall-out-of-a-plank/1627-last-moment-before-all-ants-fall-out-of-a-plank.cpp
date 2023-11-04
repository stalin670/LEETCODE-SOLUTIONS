class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size()==0){
           sort(right.begin(),right.end());
           return (n-right[0]);
        }
        else if(right.size()==0){
            sort(left.begin(),left.end(),greater<int> ());
            return left[0];
        }
        else{
            sort(left.begin(),left.end(),greater<int>());
            sort(right.begin(),right.end());
            return max(n-right[0],left[0]);
        }
    }
};