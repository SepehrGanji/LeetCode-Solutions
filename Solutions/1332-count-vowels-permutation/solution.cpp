class Solution {
public:
    const int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        int dp[5][n+10];
        dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = dp[4][0] = 1;
        for(int i = 1 ; i < n ; i++) {
            dp[0][i] = (((dp[1][i-1] + dp[4][i-1]) % mod) + dp[2][i-1]) % mod;
            dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % mod;
            dp[2][i] = (dp[1][i-1] + dp[3][i-1]) % mod;
            dp[3][i] = (dp[2][i-1]);
            dp[4][i] = (dp[2][i-1] + dp[3][i-1]) % mod;
        }
        int ans = dp[0][n-1] + dp[1][n-1];
        ans %= mod;
        ans += dp[2][n-1];
        ans %= mod;
        ans += dp[3][n-1];
        ans %= mod;
        ans += dp[4][n-1];
        ans %= mod;
        return ans;
    }
};
