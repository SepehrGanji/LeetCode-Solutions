class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        long long dp[4][n];
        long long inf = -1 * (1000000000000);
        dp[1][0] = inf;
        dp[2][0] = dp[2][1] = inf;
        dp[3][0] = dp[3][1] = dp[3][2] = inf;
        dp[0][0] = 1ll * a[0] * b[0];
        for(int j = 1 ; j < n ; j++){
            dp[0][j] = max(1ll * a[0] * b[j], dp[0][j-1]);
        }
        for(int j = 1 ; j < n ; j++) {
            for(int i = 1 ; i < 4 ; i++) {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + (1ll * a[i] * b[j]));
            }
        }
        // for(int i = 0 ; i < 4 ; i++) {
        //     for(int j = 0 ; j < n ; j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        return dp[3][n-1];
    }
};
