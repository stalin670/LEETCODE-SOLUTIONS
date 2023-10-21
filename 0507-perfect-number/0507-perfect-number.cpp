class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        long long sum=1;
        for(int i=2;i<=sqrt(num);i++){
            if(i*i==num){
                sum+=i;
            }
            else if(num%i==0){
                int x=i;
                int y=(num/i);
                sum+=x;
                sum+=y;
            }
        }
        cout<<sum<<endl;
        if(sum==num) return true;
        return false;
    }
};