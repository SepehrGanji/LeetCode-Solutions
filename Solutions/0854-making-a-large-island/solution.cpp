class UnionFind {
public:
    typedef pair<int, int> pii;
    UnionFind(int n) {
        for(int i = 0 ; i < n ; i++) {
            root.push_back({});
            usize.push_back({});
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                root[i].push_back({i, j});
                usize[i].push_back(1);
            }
        }
    }

    pii find(pii point) {
        while(point != root[point.first][point.second]) {
            point = root[point.first][point.second];
        }
        return point;
    }

    void unionSet(pii x, pii y) {
        auto rootX = find(x);
        auto rootY = find(y);
        if (rootX != rootY) {
            int n = root.size();
            if(usize[rootX.first][rootX.second] >= usize[rootY.first][rootY.second]) {
                root[rootY.first][rootY.second] = rootX;
                usize[rootX.first][rootX.second] += usize[rootY.first][rootY.second];
            } else {
                root[rootX.first][rootX.second] = rootY;
                usize[rootY.first][rootY.second] += usize[rootX.first][rootX.second];
            }
        }
    }

    bool connected(pii x, pii y) {
        return find(x) == find(y);
    }

    int getSize(int i, int j) {
        auto par = find({i, j});
        return usize[par.first][par.second];
    }

private:
    vector<vector<pii>> root;
    vector<vector<int>> usize;
};

class Solution {
public:
    int n;
    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= n) return false;
        return true;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        UnionFind uf(n);
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 0) continue;
                // right
                if(isValid(i, j+1) && grid[i][j+1] == 1) {
                    uf.unionSet({i, j}, {i, j+1});
                }
                // down
                if(isValid(i+1, j) && grid[i+1][j] == 1) {
                    uf.unionSet({i, j}, {i+1, j});
                }
            }
        }
        int dirX[] = {0, 0, 1, -1};
        int dirY[] = {1, -1, 0, 0};
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                ans = max(ans, uf.getSize(i, j));
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 0) {
                    int local_ans = 1;
                    set<pair<int, int>> st;
                    for(int d = 0 ; d < 4 ; d++) {
                        int ii = i + dirX[d], jj = j + dirY[d];
                        if(isValid(ii, jj) && grid[ii][jj] == 1) {
                            auto par = uf.find({ii, jj});
                            if(st.find({par.first, par.second}) == st.end()) {
                                local_ans += uf.getSize(ii, jj);
                                st.insert({par.first, par.second});
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
