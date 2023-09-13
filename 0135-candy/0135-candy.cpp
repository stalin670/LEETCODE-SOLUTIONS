class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(); 
        int upCount = 0, downCount = 0, peakCount = 0, totalCandies = 1;
        for(int i = 1; i < n ; i ++){
            if(ratings[i - 1] < ratings[i]){
                downCount = 0;
                upCount += 1;
                peakCount = upCount + 1;
                totalCandies += peakCount;
            } else if(ratings[i - 1] == ratings[i]){
                downCount = 0;
                upCount = 0;
                peakCount = 0;
                totalCandies += 1;
            } else {
                downCount += 1;
                upCount = 0;
                totalCandies += downCount + 1 - (peakCount > downCount);
            }
        } 
        return totalCandies;
    }
};