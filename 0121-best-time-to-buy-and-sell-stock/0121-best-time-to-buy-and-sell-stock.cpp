class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=INT_MAX;
        int final_profit=0;
        int today_profit=0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mx){
                mx=prices[i];
            }
            
            today_profit=prices[i]-mx;
            final_profit=max(final_profit,today_profit);
        }
        
        return final_profit;
    }
};