class Solution {
public:
    bool isValidPoint(int n, int i, int j) {
  if(i < 0 || i >= n) return false;
  if(j < 0 || j >= n) return false;
  return true;
}

double knightProbability(int n, int k, int row, int column) {
  double dp[101][26][26];
  for(int i = 0 ; i < k ; i++)
    for(int j = 0 ; j < n ; j++)
      for(int t = 0 ; t < n ; t++)
        dp[i][j][t] = 0;

  dp[0][row][column] = 1;
  vector<pair<int, int>> moves;
  moves.push_back({1, 2});
  moves.push_back({1, -2});
  moves.push_back({2, 1});
  moves.push_back({2, -1});
  moves.push_back({-1, 2});
  moves.push_back({-1, -2});
  moves.push_back({-2, 1});
  moves.push_back({-2, -1});
  for(int m = 1 ; m <= k ; m++) {
    for(int i = 0 ; i < n ; i++) {
      for(int j = 0 ; j < n ; j++) {
        // m, i, j
        double sum = 0;
        for(auto move: moves) {
          int ii = i + move.first, jj = j + move.second;
          if(isValidPoint(n, ii, jj))
            sum += dp[m-1][ii][jj];
        }
        dp[m][i][j] = sum / 8;
      }
    }
  }
  double ans = 0;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
      ans += dp[k][i][j];

  return ans;
}
};
