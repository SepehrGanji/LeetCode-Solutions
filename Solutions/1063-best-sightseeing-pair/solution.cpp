class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, n = values.size();
        int maxsof = values[0];
        for(int i = 1 ; i < n ; i++) {
            maxsof--;
            ans = max(ans, maxsof + values[i]);
            maxsof = max(maxsof, values[i]);
        }
        return ans;
    }
};
