class Solution {
    typedef pair<int, int> pii;
    typedef pair<int, pii> pip;
public:
    bool isValid(int n, int m, int x, int y) {
        if(x < 0 || x >= n) return false;
        if(y < 0 || y >= m) return false;
        return true;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int dirs_x[4] = {0, 0, 1, -1};
        int dirs_y[4] = {1, -1, 0 , 0};
        dist[0][0] = grid[0][0];
        pq.push(make_pair(dist[0][0], pii(0, 0)));
        while(1) {
            auto el = pq.top(); pq.pop();
            int d = el.first, x = el.second.first, y = el.second.second;
            if(x == n-1 && y == m-1) return d;
            for(int i = 0 ; i < 4 ; i++) {
                int xx = x + dirs_x[i], yy = y + dirs_y[i];
                if(isValid(n, m, xx, yy) && d + grid[xx][yy] < dist[xx][yy]) {
                    dist[xx][yy] = d + grid[xx][yy];
                    pq.push(make_pair(dist[xx][yy], pii(xx, yy)));
                }
            }
        }
        return 0;
    }
};
