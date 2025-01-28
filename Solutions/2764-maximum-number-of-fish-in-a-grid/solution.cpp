class Solution {
public:
    typedef pair<int, int> pii;

    bool isValid(int i, int j, int n, int m) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, false));
        int moves_i[] = {0, 0, 1, -1};
        int moves_j[] = {1, -1, 0, 0};
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] > 0 && !visited[i][j]) {
                    int local_ans = grid[i][j];
                    queue<pii> qu;
                    qu.push({i, j});
                    visited[i][j] = true;
                    while(!qu.empty()) {
                        auto node = qu.front(); qu.pop();
                        int ii = node.first, jj = node.second;
                        for(int k = 0 ; k < 4 ; k++) {
                            int iii = ii + moves_i[k], jjj = jj + moves_j[k];
                            if(isValid(iii, jjj, n, m) && !visited[iii][jjj] && grid[iii][jjj] > 0) {
                                local_ans += grid[iii][jjj];
                                visited[iii][jjj] = true;
                                qu.push({iii, jjj});
                            }
                        }
                    }
                    ans = max(ans, local_ans);
                }
            }
        }
        return ans;
    }
};
