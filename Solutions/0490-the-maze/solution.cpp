class Solution {
public:
    int n, m;
    bool reach[101][101];
    int dir_i[4] = {0, 0, 1, -1};
    int dir_j[4] = {1, -1, 0, 0};

    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size();
        m = maze[0].size();
        int si = start[0], sj = start[1];
        int di = destination[0], dj = destination[1];
        stack<pair<int, int>> st;
        st.push({si, sj});
        reach[si][sj] = true;
        while(!st.empty()) {
            auto el = st.top(); st.pop();
            int i = el.first, j = el.second;
            for(int k = 0 ; k < 4 ; k++) {
                int ii = i, jj = j;
                while(isValid(ii + dir_i[k], jj + dir_j[k]) && maze[ii + dir_i[k]][jj + dir_j[k]] == 0) {
                    ii += dir_i[k];
                    jj += dir_j[k];
                }
                if(!reach[ii][jj]) {
                    reach[ii][jj] = true;
                    st.push({ii, jj});
                }
            }
        }
        return reach[di][dj];
    }
};
