class Solution {
public:
    int old_col;
    int new_col;
    int n, m;
    bool done[100][100];

    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }

    void fff(vector<vector<int>>& arr, int i, int j) {
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};
        for(int k = 0 ; k < 4 ; k++) {
            int ii = i + dir_x[k], jj = j + dir_y[k];
            if(isValid(ii, jj) && arr[ii][jj] == old_col && done[ii][jj] == false) {
                arr[ii][jj] = new_col;
                done[ii][jj] = true;
                fff(arr, ii, jj);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& arr, int ii, int jj, int nnn) {
        old_col = arr[ii][jj];
        new_col = nnn;
        n = arr.size(), m = arr[0].size();
        arr[ii][jj] = new_col;
        done[ii][jj] = true;
        fff(arr, ii, jj);
        return arr;
    }
};
