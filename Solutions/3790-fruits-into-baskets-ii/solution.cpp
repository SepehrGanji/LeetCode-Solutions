class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> av(n, true);
        int ans = 0;
        for(auto fr: fruits) {
            bool placed = false;
            for(int i = 0 ; i < n ; i++) {
                if(av[i] && baskets[i] >= fr) {
                    av[i] = false;
                    placed = true;
                    break;
                }
            }
            if(!placed) ans++;
        }
        return ans;
    }
};
