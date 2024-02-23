class Solution {
public:
bool row[11][11];
bool col[11][11];
bool box[11][11];

int getBoxId(int i, int j) {
  int rowVal = (i / 3) * 3;
  int colVal = j / 3;
  return rowVal + colVal;
}

pair<int,int> nextIJ(int i , int j) {
  if(j < 9) return {i, j + 1};
  return {i + 1, 0};
}

bool isValidChoice(vector<vector<char>>& ans, int i, int j, int el) {
  if(row[i][el] || col[j][el] || box[getBoxId(i, j)][el])
    return false;
  return true;
}

bool recurse(vector<vector<char>>& ans, int i, int j) {
  // Terminate
  if(i == 9) return true;
  if(ans[i][j] == '.') {
    // Place something
    for(int el = 1 ; el < 10 ; el++) {
      if(isValidChoice(ans, i, j, el)) {
        // adding
        ans[i][j] = '0' + el;
        row[i][el] = true;
        col[j][el] = true;
        box[getBoxId(i, j)][el] = true;
        // recursing
        pair<int, int> pii = nextIJ(i, j);
        if(recurse(ans, pii.first, pii.second))
          return true;
        // reseting
        ans[i][j] = '.';
        row[i][el] = false;
        col[j][el] = false;
        box[getBoxId(i, j)][el] = false;
      }
    }
    return false;
  } else {
    // Just move to the next one!
    pair<int, int> pii = nextIJ(i, j);
    return recurse(ans, pii.first, pii.second);
  }
}

void solveSudoku(vector<vector<char>>& board) {
  for(int i = 0 ; i < 11 ; i++)
    for(int j = 0 ; j < 11 ; j++)
      row[i][j] = false, col[i][j] = false, box[i][j] = false;

  // PreProccess
  for(int i = 0 ; i < 9 ; i++)
    for(int j = 0 ; j < 9 ; j++)
      if(board[i][j] != '.') {
        int el = board[i][j] - '0';
        row[i][el] = true;
        col[j][el] = true;
        box[getBoxId(i, j)][el] = true;
      }
  recurse(board, 0, 0);
}
};
