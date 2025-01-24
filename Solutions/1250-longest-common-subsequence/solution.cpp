class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1010][1010];
        int n = text1.length(), m = text2.length();
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++) 
            dp[i][j] = 0;

        // base case
        if(text1[0] == text2[0]) dp[0][0] = 1;
        for(int j = 1 ; j < m ; j++) {
            dp[0][j] = text1[0] == text2[j] ? 1 : dp[0][j-1]; 
        }
        for(int i = 1 ; i < n ; i++) {
            dp[i][0] = text1[i] == text2[0] ? 1 : dp[i-1][0]; 
        }

        // now let's do DP!
        for(int i = 1 ; i < n ; i++) 
            for(int j = 1 ; j < m ; j++) {
            if(text1[i] == text2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        return dp[n-1][m-1];
    }
};
