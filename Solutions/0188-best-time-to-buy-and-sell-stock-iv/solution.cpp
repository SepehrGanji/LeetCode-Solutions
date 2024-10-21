class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][k+1][2];
        for(int i = 0 ; i <= n ; i++) dp[i][0][0] = dp[i][0][1] = 0;
        for(int r = 0 ; r <= k ; r++) dp[n][r][0] = dp[n][r][1] = 0;
        for(int i = n-1 ; i >= 0 ; i--) {
            for(int r = 1 ; r <= k ; r++) {
                // don't have
                dp[i][r][0] = max(dp[i+1][r][0], -prices[i] + dp[i+1][r][1]);
                // do have
                dp[i][r][1] = max(dp[i+1][r][1], prices[i] + dp[i+1][r-1][0]);
            }
        }
        return dp[0][k][0];
    }
};
