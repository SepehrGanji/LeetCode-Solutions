class Solution {
public:
    int n, m;
    
    bool isValid(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        if(grid[i][j] == 'W') return false;
        return true;
    }
    
    int how_many(vector<vector<char>>& grid, int i, int j) {
        int ans = 0;
        //forward
        int ii = i, jj = j;
        while(isValid(grid, ii, jj)) {
            if(grid[ii][jj] == 'E') ans++;
            jj++;
        }
        //backward
        ii = i, jj = j;
        while(isValid(grid, ii, jj)) {
            if(grid[ii][jj] == 'E') ans++;
            jj--;
        }
        
        //down
        ii = i, jj = j;
        while(isValid(grid, ii, jj)) {
            if(grid[ii][jj] == 'E') ans++;
            ii++;
        }
        
        //up
        ii = i, jj = j;
        while(isValid(grid, ii, jj)) {
            if(grid[ii][jj] == 'E') ans++;
            ii--;
        }
        
        return ans;
    }
    
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j] == '0') ans = max(ans, how_many(grid, i, j));
        return ans;
    }
};
