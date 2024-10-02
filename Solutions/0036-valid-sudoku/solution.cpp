class Solution {
public:
    bool valLine(vector<vector<char>>& board, int s, bool row) {
        bool seen[10]; for(int i = 0 ; i < 10 ; i++) seen[i] = false;
        if(row) {
            for(int j = 0 ; j < 9 ; j++) {
                int ch = board[s][j] - '0';
                if(ch < 0) continue;
                if(seen[ch]) return false;
                seen[ch] = true;
            }
        } else {
            for(int i = 0 ; i < 9 ; i++) {
                int ch = board[i][s] - '0';
                if(ch < 0) continue;
                if(seen[ch]) return false;
                seen[ch] = true;
            }
        }
        return true;
    }

    bool valSquare(vector<vector<char>>& board, int x, int y) {
        bool seen[10]; for(int i = 0 ; i < 10 ; i++) seen[i] = false;
        for(int i= x ; i < x+3 ; i++) {
            for(int j = y ; j < y + 3 ; j++) {
                int ch = board[i][j] - '0';
                if(ch < 0) continue;
                if(seen[ch]) return false;
                seen[ch] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++) {
            if(!valLine(board, i, true)) return false;
            if(!valLine(board, i, false)) return false;
        }
        for(int i = 0 ; i <= 6 ; i += 3)
            for(int j = 0; j <= 6 ; j += 3)
                if(!valSquare(board, i, j)) return false;
        return true;
    }
};
