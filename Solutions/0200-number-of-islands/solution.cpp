class Solution {
public:
    bool arr[303][303];
    int n, m;
    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};
        for(int k = 0 ; k < 4 ; k++) {
            int ii = i + dir_x[k], jj = j + dir_y[k];
            if(isValid(ii, jj) && grid[ii][jj] == '1' && arr[ii][jj] == false) {
                arr[ii][jj] = true;
                dfs(grid, ii, jj);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j] == '1' && arr[i][j] == false) {
                    ans++;
                    arr[i][j] = true;
                    dfs(grid, i, j);
                }
        return ans;
    }
};

