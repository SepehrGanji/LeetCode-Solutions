class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, int> mp;
        for(auto el: candyType) mp[el]++;
        int n = candyType.size();
        int m = mp.size();
        return min(n/2, m);
    }
};
