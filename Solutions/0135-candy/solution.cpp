class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> cand;
        for(int i = 0 ; i < n ; i++) cand.push_back(1);
        for(int i = 1 ; i < n ; i++) if(ratings[i] > ratings[i-1]) cand[i] = cand[i-1] + 1;
        for(int i = n - 2 ; i >= 0 ; i--) if(ratings[i] > ratings[i+1]) cand[i] = max(cand[i], cand[i+1]+1);
        int ans = 0;
        for(auto el: cand) ans += el;
        return ans;
    }
};
