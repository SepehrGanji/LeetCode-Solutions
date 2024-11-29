class Solution {
public:
    typedef pair<int, int> pii;
    typedef pair<int, pii> pip;

    bool isValid(int n, int m, int x, int y) {
        if(x < 0 || x >= n) return false;
        if(y < 0 || y >= m) return false;
        return true;
    }

    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        priority_queue<pip, vector<pip>, greater<>> pq;
        vector<vector<int>> visited(n, vector<int>(m, false));
        pq.push(make_pair(0, pii(0, 0)));
        visited[0][0] = true;
        int dirs_x[4] = {0, 0, 1, -1};
        int dirs_y[4] = {1, -1, 0, 0};
        while(1) {
            auto el = pq.top(); pq.pop();
            int t = el.first, x = el.second.first, y = el.second.second;
            if(x == n-1 && y == m-1) return t;
            for(int d = 0 ; d < 4 ; d++) {
                int xx = x + dirs_x[d], yy = y + dirs_y[d];
                if(isValid(n, m, xx, yy) && !visited[xx][yy]) {
                    visited[xx][yy] = true;
                    int waitTime = ((grid[xx][yy] - t) % 2 == 0) ? 1 : 0;
                    int nextTime = max(grid[xx][yy] + waitTime, t + 1);
                    pq.push(make_pair(nextTime, pii(xx, yy)));
                }
            }
        }
        return 0;
    }
};
