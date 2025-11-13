class FoodRatings {
public:
    struct Compare {
    bool operator()(const pair<string,int>& a,
                    const pair<string,int>& b) const {
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }
    };
    unordered_map<string, pair<string, int>> mp1; // food -> cuis, rating
    unordered_map<string, set<pair<string, int>, Compare>> mp2; // cous -> food, rating

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0 ; i < foods.size() ; i++) {
            string food = foods[i], cuis = cuisines[i];
            int rating = ratings[i];
            mp1[food] = {cuis, rating};
            mp2[cuis].insert({food, rating});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto old = mp1[food];
        mp2[old.first].erase({food, old.second});
        mp1[food] = {old.first, newRating};
        mp2[old.first].insert({food, newRating});
    }
    
    string highestRated(string cuisine) {
        return (*mp2[cuisine].begin()).first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
