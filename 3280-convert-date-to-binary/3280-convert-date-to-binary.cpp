class Solution {
public:
    #define ll long long
    
    string fun(ll n) {
        string x = "";
        while(n) {
            ll rem = n % 2;
            if(rem == 0)
                x += "0";
            else
                x += "1";
            n /= 2;
        }
        reverse(x.begin(), x.end());
        ll ind = 0;
        while(x[ind] == '0')
            ind++;
        return x.substr(ind, x.size() - ind);
    }
    
    string convertDateToBinary(string date) {
        ll year = stoi(date.substr(0, 4));
        ll month;
        if(date[5] == '0') {
            month = stoi(date.substr(6, 1));
        }
        else {
            month = stoi(date.substr(5, 2));
        }
        ll day;
        if(date[8] == '0') {
            day = stoi(date.substr(9, 1));
        }
        else {
            day = stoi(date.substr(8, 2));
        }
        
        string binYear = fun(year);
        string binMonth = fun(month);
        string binDay = fun(day);
        
        string ans = binYear + "-" + binMonth + "-" + binDay;
        return ans;
    }
};