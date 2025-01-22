class Solution {
public:
    int n, m;

    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(isWater[i][j]) {
                    ans[i][j] = 0;
                    q.push(make_pair(i, j));
                } 
        int h = 1;
        int dirx[] = {0, 0, 1, -1};
        int diry[] = {1, -1, 0, 0};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front(); q.pop();
                for(int i = 0 ; i < 4 ; i++) {
                    int x = curr.first + dirx[i], y = curr.second + diry[i];
                    if(isValid(x, y) && ans[x][y] == -1) {
                        ans[x][y] = h;
                        q.push(make_pair(x, y));
                    }
                }
            }
            h++;
        }
        return ans;
    }
};
