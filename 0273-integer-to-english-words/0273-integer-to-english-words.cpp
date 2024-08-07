class Solution {
public:
    string two_digit(int n, vector<string> first, vector<string> second) {
        if (n < 20) return first[n];
        else {
            int tens = n / 10;
            int ones = n % 10;
            return second[tens] + (ones == 0 ? "" : " " + first[ones]);
        }
    }
    
    string three_digit(int n, vector<string> first, vector<string> second) {
        if (n == 0) return string("");
        if (n < 100) return two_digit(n, first, second);
        return first[n / 100] + " Hundred" + (n % 100 == 0 ? "" : " " + two_digit(n % 100, first, second));
    }
    
    string numberToWords(int n) {
        if(n == 0) 
            return "Zero"; 
        
        vector<string> first = {
                                "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", 
                                "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
                                };
        
        vector<string> second = {
                                "", "", "Twenty", "Thirty", "Forty", "Fifty", 
                                "Sixty", "Seventy", "Eighty", "Ninety"
                                };
        
        
        int billion = n / 1000000000;
        int million = (n / 1000000) % 1000;
        int thousand = (n / 1000) % 1000;
        int hundred = n % 1000;
        
        string ans;
        if (billion) ans += three_digit(billion, first, second) + " Billion";
        if (million) ans += (ans.empty() ? "" : " ") + three_digit(million, first, second) + " Million";
        if (thousand) ans += (ans.empty() ? "" : " ") + three_digit(thousand, first, second) + " Thousand";
        if (hundred) ans += (ans.empty() ? "" : " ") + three_digit(hundred, first, second);

        return ans;
        
    }
};