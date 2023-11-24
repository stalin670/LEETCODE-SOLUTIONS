class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i=0,j=piles.size()-1;
        int k=0,ans=0;
        while(i<=j){
            if(k==0){
                i++;
                j--;
                k++;
            }
            else {
                ans+=piles[j];
                j--;
                k=0;
            }
        }
        return ans;
    }
};