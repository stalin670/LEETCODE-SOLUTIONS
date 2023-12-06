class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int st=1;
        int curr=1;
        int i=1;
        int day=0;
        while(i<=n){
            ans+=curr;
            curr++;
            day++;
            if(day==7){
                day=0;
                st++;
                curr=st;
            }
            i++;
        }
        return ans;
    }
};