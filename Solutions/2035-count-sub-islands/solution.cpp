class Solution {
public:
    typedef pair<int, int> pii;
    int n, m;

    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        vector<vector<pii>> arr;
        // day kasra
        int dir_x[] = {0, 0, 1, -1};
        int dir_y[] = {1, -1, 0, 0};
        n = grid1.size();
        m = grid1[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid2[i][j] == 1 && !seen[i][j]) {
                    arr.push_back({});
                    int idx = arr.size()-1;
                    stack<pii> st; 
                    seen[i][j] = true; st.push({i, j});
                    while(!st.empty()) {
                        auto el = st.top(); st.pop();
                        int ii = el.first, jj = el.second;
                        arr[idx].push_back({ii, jj});
                        for(int k = 0 ; k < 4 ; k++) {
                            int ai = ii + dir_x[k], aj = jj + dir_y[k];
                            if(isValid(ai, aj) && grid2[ai][aj] == 1 && seen[ai][aj] == 0) {
                                seen[ai][aj] = true; st.push({ai, aj});
                            }
                        } 
                    }
                }
            }
        }
        // gr check
        for(auto island: arr) {
            bool all = true;
            for(auto cell: island) {
                if(grid1[cell.first][cell.second] == 0) all = false;
            }
            if(all) ans++;
        }
        return ans;
    }
};
