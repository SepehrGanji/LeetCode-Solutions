class Solution {
public:
    int n, m;
    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size(); m = grid[0].size();
        int visited[n][m]; 
        for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) visited[i][j] = 0;
        visited[0][0] = health-grid[0][0];
        queue<pair<int, int>> qu;
        qu.push(make_pair(0, 0));
        int myNum[4] = {0, 0, 1, -1};
        int myNum2[4] = {1, -1, 0, 0};
        while(!qu.empty()) {
            auto el = qu.front(); qu.pop();
            int i = el.first, j = el.second;
            int curr_health = visited[i][j];
            if(i == n-1 && j == m-1 && curr_health > 0) {
                //cout << "CURRHEALTH: " << curr_health << endl;
                return true;
            }
            for(int em = 0 ; em < 4 ; em++) {
                int ii = i + myNum[em], jj = j + myNum2[em];
                if(!isValid(ii, jj)) continue;
                int red = grid[ii][jj];
                if(curr_health-red > visited[ii][jj]) {
                    visited[ii][jj] = curr_health - red;
                    qu.push(make_pair(ii, jj));
                }
            }
        }
        return false;
    }
};
