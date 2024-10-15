class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        int dp[m+1][m+1];
        for(int i = m; i >= 0 ; i--) dp[i][m] = dp[m][i] = 0;

        for(int i = m - 1 ; i >= 0 ; i--) {
            for(int l = i ; l >= 0 ; l--) {
                int mult = multipliers[i];
                int r = n - 1 - (i - l);
                dp[i][l] = max(mult * nums[l] + dp[i+1][l+1], mult * nums[r] + dp[i+1][l]);
            }
        }
        return dp[0][0];
    }
};
