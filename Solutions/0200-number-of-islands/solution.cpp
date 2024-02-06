class Solution {
public:
    bool isValidPoint(int i, int j, int M, int N) {
  if(i < 0 || i >= M) return false;
  if(j < 0 || j >= N) return false;
  return true;
}

void detectMe(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
  queue<pair<int, int>> qu;
  int M = grid.size();
  int N = grid[0].size();
  // M * N
  qu.push({i, j});
  while(!qu.empty()) {
    pair<int, int> pp = qu.front(); qu.pop();
    int ii = pp.first, jj = pp.second;
    if(grid[ii][jj] == '1') {
      visited[ii][jj] = true;
      if(isValidPoint(ii-1, jj, M, N) && !visited[ii-1][jj]){
        qu.push({ii - 1, jj});
        visited[ii-1][jj] = true;
      }

      if(isValidPoint(ii+1, jj, M, N) && !visited[ii+1][jj]){
        qu.push({ii + 1, jj});
        visited[ii+1][jj] = true;
      }

      if(isValidPoint(ii, jj-1, M, N) && !visited[ii][jj-1]){
        qu.push({ii, jj - 1});
        visited[ii][jj-1] = true;
      }

      if(isValidPoint(ii, jj+1, M, N) && !visited[ii][jj+1]){
        qu.push({ii, jj + 1});
        visited[ii][jj+1] = true;
      }
    }
  }
}

int numIslands(vector<vector<char>>& grid) {
  vector<vector<bool>> visited;
  for(int i = 0 ; i < grid.size() ; i++) {
    visited.push_back({});
    for(int j = 0 ; j < grid[i].size() ; j++) {
      visited[i].push_back(false);
    }
  }
  int ans = 0;
  for(int i = 0 ; i < grid.size() ; i++) {
    for(int j = 0 ; j < grid[i].size() ; j++) {
      if(grid[i][j] == '1' && !visited[i][j]) {
        ans++;
        detectMe(i, j, grid, visited);
      }
    }
  }
  return ans;
}
};
