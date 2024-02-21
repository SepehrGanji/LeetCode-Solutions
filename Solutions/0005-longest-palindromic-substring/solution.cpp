class Solution {
public:
    string longestPalindrome(string s) {
  int n = s.length();
  bool dp[1010][1010];
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
      dp[i][j] = false;
  
  for(int i = 0 ; i < n ; i++) {
    dp[i][i] = true;
    if(i < n - 1 && s[i] == s[i+1]) {
      dp[i][i+1] = true;
    }
  }

  for(int L = 2 ; L < n ; L++) {
    for(int i = 0 ; i < n ; i++) {
      int j = i + L;
      if(j >= n) break;
      if(s[i] == s[j] && dp[i+1][j-1] == true)
        dp[i][j] = true;
    }
  }

  int maxL = -1;
  int maxi, maxj;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) {
      if(dp[i][j]) {
        if(j - i > maxL) {
          maxL = j - i;
          maxi = i;
          maxj = j;
        }
      }
    }
  }
  string ans = "";
  for(int i = maxi ; i <= maxj ; i++)
    ans += s[i];

  return ans;
}
};