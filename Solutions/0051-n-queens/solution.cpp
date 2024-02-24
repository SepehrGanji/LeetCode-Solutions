class Solution {
public:
    bool col[22], d1[22], d2[22];
char board[10][10];
int N = 0;
vector<vector<string>> ans = {};

bool canPlace(int r, int c) {
  if(col[c] || d1[r+c] || d2[r-c+N])
    return false;
  return true;
}

void place(int r, int c) {
  board[r][c] = 'Q';
  col[c] = true;
  d1[r+c] = true;
  d2[r-c+N] = true;
}

void unPlace(int r, int c) {
  board[r][c] = '.';
  col[c] = false;
  d1[r+c] = false;
  d2[r-c+N] = false;
}

void reset() {
  for(int i = 0 ; i < 22 ; i++) {
    col[i] = false;
    d1[i] = false;
    d2[i] = false;
  }
  for(int i = 0 ; i < N ; i++) 
    for(int j = 0 ; j < N ; j++)
      board[i][j] = '.';
}

void start(int r) {
  if(r >= N) {
    vector<string> bb;
    for(int i = 0 ; i < N ; i++) {
      string tmp = "";
      for(int j = 0 ; j < N ; j++) tmp += board[i][j];
      bb.push_back(tmp);
      cout << tmp << endl;
    }
    ans.push_back(bb);
  }
  for(int c = 0 ; c < N ; c++) {
    if(canPlace(r, c)) {
      place(r, c);
      start(r + 1);
      unPlace(r, c);
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  N = n;
  reset();
  start(0);
  return ans;
}
};
