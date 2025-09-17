class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = (int)foods.size();
        food_info.reserve(n);
        for (int i = 0; i < n; ++i) {
            const string& f = foods[i];
            const string& c = cuisines[i];
            int r = ratings[i];
            food_info[f] = {c, r};                
            by_cuisine[c].insert({-r, f});          
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cui, oldR] = food_info[food];
        auto& S = by_cuisine[cui];
        S.erase({-oldR, food});                     
        S.insert({-newRating, food});               
        oldR = newRating;                           
    }
    
    string highestRated(string cuisine) {
        return by_cuisine[cuisine].begin()->second;
    }

private:
    unordered_map<string, pair<string,int>> food_info;      
    unordered_map<string, set<pair<int,string>>> by_cuisine; 
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */