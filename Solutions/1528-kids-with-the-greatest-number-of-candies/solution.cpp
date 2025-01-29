class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int gr = 0;
        for(auto el: candies) gr = max(gr, el);
        vector<bool> ans;
        for(auto el: candies)
            if(el + extraCandies >= gr) ans.push_back(1);
            else ans.push_back(0);
        return ans;
    }
};
