class FoodRatings {
public:
    map<string, pair<string, int>> arr;
    map<string, map<int, set<string>>> brr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            arr[foods[i]] = {cuisines[i], ratings[i]};
            brr[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto foodInfo = arr.find(food);
        string cuisine = foodInfo->second.first;
        int oldRating = foodInfo->second.second;
        foodInfo->second.second = newRating;

        brr[cuisine][oldRating].erase(food);
        if (brr[cuisine][oldRating].empty())
            brr[cuisine].erase(oldRating);

        brr[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *brr[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */