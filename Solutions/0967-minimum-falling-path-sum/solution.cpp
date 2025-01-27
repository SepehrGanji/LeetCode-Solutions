class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j = 0 ; j < m ; j++) dp[0][j] = matrix[0][j];
        for(int i = 1 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++) {
                int mini = dp[i-1][j];
                if(j > 0) mini = min(mini, dp[i-1][j-1]);
                if(j < m-1) mini = min(mini, dp[i-1][j+1]);
                dp[i][j] = matrix[i][j] + mini;
            }
        int ans = dp[n-1][0];
        for(int j = 1 ; j < m ; j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
};
