class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        // 0 -> Don't have
        // 1 -> Have
        dp[1][0] = -1 * prices[0];
        for(int i = 1 ; i < n ; i++) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1] + prices[i] - fee);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i]);
        }
        return dp[0][n-1];
    }
};
