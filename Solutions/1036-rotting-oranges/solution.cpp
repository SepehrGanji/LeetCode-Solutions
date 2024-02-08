class Solution {
public:
    bool isValidPoint(int i, int j, int M, int N) {
  if(i < 0 || i >= M) return false;
  if(j < 0 || j >= N) return false;
  return true;
}

int orangesRotting(vector<vector<int>>& grid) {
  int fresh_count = 0;
  int M = grid.size(), N = grid[0].size();
  queue<pair<int, int>> qu;
  for(int i = 0 ; i < M ; i++) {
    for(int j = 0 ; j < N ; j++) {
      if(grid[i][j] == 1) fresh_count++;
      else if(grid[i][j] == 2) qu.push({i, j});
    }
  }

  int q_len = qu.size();
  int ans = -1;
  while(!qu.empty()) {
    pair<int, int> p = qu.front(); qu.pop(); q_len--;
    int i = p.first, j = p.second;
    if(isValidPoint(i-1, j, M, N) && grid[i-1][j] == 1) {
      qu.push({i-1, j});
      grid[i-1][j] = 2;
      fresh_count--;
    }
    if(isValidPoint(i+1, j, M, N) && grid[i+1][j] == 1) {
      qu.push({i+1, j});
      grid[i+1][j] = 2;
      fresh_count--;
    }
    if(isValidPoint(i, j-1, M, N) && grid[i][j-1] == 1) {
      qu.push({i, j-1});
      grid[i][j-1] = 2;
      fresh_count--;
    }
    if(isValidPoint(i, j+1, M, N) && grid[i][j+1] == 1) {
      qu.push({i, j+1});
      grid[i][j+1] = 2;
      fresh_count--;
    }
    if(q_len == 0) {
      ans++;
      q_len = qu.size();
    }
  }

  if(fresh_count > 0) return -1;
  if(ans == -1) return 0;
  return ans;
}
};
