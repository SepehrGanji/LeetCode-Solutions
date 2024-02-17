class Solution {
public:
    int longestPalindromeSubseq(string s) {
  int n = s.length();
  string s2 = "";
  for(int i = n - 1 ; i > -1 ; i--) s2 += s[i];
  int dp[1010][1010];
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
      dp[i][j] = 0;
  // first row and column
  if(s[0] == s2[0]) dp[0][0] = 1;
  for(int j = 1 ; j < n ; j++) {
    int i = 0;
    if(dp[i][j-1] == 1) dp[i][j] = 1;
    else if(s[i] == s2[j]) dp[i][j] = 1;
  }
  for(int i = 1 ; i < n ; i++) {
    int j = 0;
    if(dp[i-1][j] == 1) dp[i][j] = 1;
    else if(s[i] == s2[j]) dp[i][j] = 1;
  }
  // now let's do dp
  for(int i = 1 ; i < n ; i++) {
    for(int j = 1 ; j < n ; j++) {
      if(s[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  }
  return dp[n-1][n-1];
}
};
