class Solution {
public:
    long dp[303][303];
    int numberOfWays(int n, int x) {
        for(int i = 0 ; i <= n ; i++) {
            dp[i][0] = 0;
            dp[0][i] = 1;
        }
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                dp[i][j] = dp[i][j-1];
                if(i - pow(j, x) >= 0) {
                    dp[i][j] += dp[i-int(pow(j, x))][j-1];
                }
                dp[i][j] %= int(1e9+7);
            }
        }
        return dp[n][n];
    }
};
