class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(i == 0 && j == 0) continue;
                if(obstacleGrid[i][j] != 1) {
                    int ans = 0;
                    if(i > 0) ans += dp[i-1][j];
                    if(j > 0) ans += dp[i][j-1];
                    dp[i][j] = ans;
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        return dp[n-1][m-1];
    }
};
