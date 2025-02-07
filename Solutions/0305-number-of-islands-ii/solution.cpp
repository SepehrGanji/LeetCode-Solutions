class UnionFind {
public:
    typedef pair<int, int> pii;
    UnionFind(int n, int m) {
        for(int i = 0 ; i < n ; i++) {
            root.push_back({});
            usize.push_back({});
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
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
            //int n = root.size();
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
    int em, en;

    bool isValid(int i, int j) {
        if(i < 0 || i >= en) return false;
        if(j < 0 || j >= em) return false;
        return true;
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int numIs = 0;
        em = n, en = m;
        vector<int> ans;
        UnionFind uf(en, em);
        vector<vector<bool>> arr(m, vector<bool>(n, false));
        int dirX[] = {0, 0, -1, 1};
        int dirY[] = {-1, 1, 0, 0};
        for(auto pi: positions) {
            int x = pi[0], y = pi[1];
            if(arr[x][y]) {
                ans.push_back(numIs);
                continue;
            }
            bool done = false;
            for(int d = 0 ; d < 4 ; d++) {
                int xx = x+dirX[d], yy = y+dirY[d];
                if(isValid(xx, yy) && arr[xx][yy]) {
                    uf.unionSet({x, y}, {xx, yy});
                    done = true;
                    break;
                }
            }
            if(done) {
                for(int d = 0 ; d < 4 ; d++) {
                int xx = x+dirX[d], yy = y+dirY[d];
                    if(isValid(xx, yy) && arr[xx][yy]) {
                        if(!uf.connected({x, y}, {xx, yy})) {
                            numIs--;
                            uf.unionSet({x, y}, {xx, yy});
                        }
                    }
                }
            } else {
                numIs++;
            }
            arr[x][y] = true;
            ans.push_back(numIs);
        }

        return ans;
    }
};
