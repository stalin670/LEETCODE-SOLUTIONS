class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=prices[0];
        int currProfit=0,totalProfit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            currProfit=prices[i]-minPrice;
            totalProfit=max(totalProfit,currProfit);
        }
        return totalProfit;
    }
};