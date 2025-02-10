class Solution {
public:
    int n, m;

    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int ans = 0;
        queue<pair<int, int>> qu;
        visited[i][j] = true;
        qu.push({i, j});
        int dirX[] = {0, 0, -1, 1};
        int dirY[] = {-1, 1, 0, 0};
        while(!qu.empty()) {
            auto to = qu.front(); qu.pop();
            int ii = to.first, jj = to.second;
            ans++;
            for(int d = 0 ; d < 4 ; d++) {
                int x = ii + dirX[d], y = jj + dirY[d];
                if(isValid(x, y) && grid[x][y] == 1 && !visited[x][y]) {
                    visited[x][y] = true;
                    qu.push({x, y});
                }
            }
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1 && !seen[i][j]) {
                    ans = max(ans, bfs(i, j, grid, seen));
                }
            }
        }
        return ans;
    }
};
