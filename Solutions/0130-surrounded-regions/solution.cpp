class Solution {
public:
    int m, n;

    bool isValid(int i, int j) {
        if(i < 0 || i >= m) return false;
        if(j < 0 || j >= n) return false;

        return true;
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        int dp[m][n];
        for(int i = 0 ; i < m ; i++) for(int j = 0 ; j < n ; j++) dp[i][j] = 0;
        queue<pair<int, int>> qu;
        for(int i = 0 ; i < m ; i++) for(int j = 0 ; j < n ; j++) {
            if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                if(board[i][j] == 'O') {
                    dp[i][j] = 1;
                    qu.push(make_pair(i, j));
                }
            }
        }
        int dir_i[4] = {0, 0, 1, -1};
        int dir_j[4] = {1, -1, 0, 0};
        while(!qu.empty()) {
            auto top = qu.front(); qu.pop();
            int i = top.first, j = top.second;
            for(int d = 0 ; d < 4 ; d++) {
                int ii = i + dir_i[d], jj = j + dir_j[d];
                if(isValid(ii, jj) && board[ii][jj] == 'O' && dp[ii][jj] != 1) {
                    dp[ii][jj] = 1;
                    qu.push(make_pair(ii, jj));
                }
            }
        }
        for(int i = 0 ; i < m ; i++) for(int j = 0 ; j < n ; j++) 
            if(dp[i][j] == 0) board[i][j] = 'X';
    }
};
