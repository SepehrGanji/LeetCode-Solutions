class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++) dp[i][j] = matrix[i][j] - '0';
        ///
        for(int i = 1 ; i < n ; i++)
            for(int j = 1 ; j < m ; j++)
                if(dp[i][j] == 1) dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
        ///
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++) ans = max(ans, dp[i][j]);
        return ans*ans;
    }
};
