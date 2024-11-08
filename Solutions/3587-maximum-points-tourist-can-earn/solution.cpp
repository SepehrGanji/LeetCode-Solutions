class Solution {
public:
    int dp[202][202];

    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        for(int x = 0 ; x < n ; x++) dp[k][x] = 0;
        for(int d = k-1 ; d >= 0 ; d--) {
            for(int x = 0 ; x < n ; x++) {
                // day d, cell x
                int ans = dp[d+1][x] + stayScore[d][x];
                for(int y = 0 ; y < n ; y++) {
                    if(y != x) {
                        ans = max(ans, dp[d+1][y] + travelScore[x][y]);
                    }
                }
                dp[d][x] = ans;
            }
        }
        int ans = 0;
        for(int x = 0 ; x < n ; x++) ans = max(ans, dp[0][x]);
        return ans;
    }
};
