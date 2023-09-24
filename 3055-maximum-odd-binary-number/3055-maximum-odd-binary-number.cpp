class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        int i=0,n=s.size();
        while(i<n && s[i]=='1') i++;
        if(i==n) return s;
        swap(s[i-1],s[n-1]);
        return s;
    }
};