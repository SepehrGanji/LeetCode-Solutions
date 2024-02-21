class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
  int dp[10010];
  for(int i = 0 ; i <= amount ; i++) {
    dp[i] = INT_MAX-1;
  }
  dp[0] = 0;
  for(int i = 1 ; i <= amount ; i++) {
    for(auto c: coins) {
      if(i - c >= 0) {
        dp[i] = min(dp[i], dp[i-c] + 1);
      }
    }
  }

  return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
}
};