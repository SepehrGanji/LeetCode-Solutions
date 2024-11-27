class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        dp.assign(triangle.begin(), triangle.end());
        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < triangle[i].size() ; j++) {
                int mini = INT_MAX;
                if(j-1 >= 0) mini = min(mini, dp[i-1][j-1]);
                if(j < dp[i-1].size()) mini = min(mini, dp[i-1][j]);
                dp[i][j] = mini + triangle[i][j];
            }
        }
        int ans = INT_MAX;
        for(int j = 0 ; j < dp[n-1].size() ; j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
};
