class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+10][2];
        for(int i = 0 ; i < n + 10 ; i++) dp[i][0] = dp[i][1] = 0;
        for(int i = n - 1 ; i >= 0 ; i--) {
            dp[i][0] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
            dp[i][1] = max(dp[i+1][1], prices[i] + dp[i+2][0]);
        }
        return dp[0][0];
    }
};
