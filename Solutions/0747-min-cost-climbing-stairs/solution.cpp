class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
  int n = cost.size();
  vector<int> dp(n+1, INT_MAX);
  dp[0] = 0, dp[1] = 0;
  // a b c
  int a = 0, b = 0;
  for(int i = 2 ; i <= n ; i++) {
    int tmp = min(b + cost[i-1], a + cost[i-2]);
    a = b;
    b = tmp;
  }
  return b;
}
};
