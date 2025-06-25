class Solution {
public:
    bool marked[303][303];
    int n, m;
    
    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> qq;
        marked[i][j]= true;
        qq.push({i, j});
        int dirs_i[4] = {0, 0, 1, -1};
        int dirs_j[4] = {1, -1, 0, 0};
        while(!qq.empty()) {
            auto el = qq.front(); qq.pop();
            int ii = el.first, jj = el.second;
            for(int k = 0 ; k < 4 ; k++) {
                int new_i = ii + dirs_i[k], new_j = jj + dirs_j[k];
                if(isValid(new_i, new_j) && grid[new_i][new_j] == '1' && !marked[new_i][new_j]) {
                    marked[new_i][new_j] = true;
                    qq.push({new_i, new_j});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        // init marked?!
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == '1' && !marked[i][j]) {
                    ans++;
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
