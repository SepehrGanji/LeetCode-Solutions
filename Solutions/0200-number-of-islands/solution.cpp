class Solution {
public:
    bool isValidPoint(int i, int j, int M, int N) {
  if(i < 0 || i >= M) return false;
  if(j < 0 || j >= N) return false;
  return true;
}

void detectMe(int i, int j, vector<vector<char>>& grid) {
  int M = grid.size();
  int N = grid[0].size();
  grid[i][j] = '0';
  if(isValidPoint(i-1, j, M, N) && grid[i-1][j] == '1') detectMe(i-1, j, grid);
  if(isValidPoint(i+1, j, M, N) && grid[i+1][j] == '1') detectMe(i+1, j, grid);
  if(isValidPoint(i, j-1, M, N) && grid[i][j-1] == '1') detectMe(i, j-1, grid);
  if(isValidPoint(i, j+1, M, N) && grid[i][j+1] == '1') detectMe(i, j+1, grid);
}

int numIslands(vector<vector<char>>& grid) {
  int ans = 0;
  for(int i = 0 ; i < grid.size() ; i++) {
    for(int j = 0 ; j < grid[i].size() ; j++) {
      if(grid[i][j] == '1') {
        ans++;
        detectMe(i, j, grid);
      }
    }
  }
  return ans;
}
};
