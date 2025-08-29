class Solution {
public:
    typedef pair<int, int> pii;
    int n, m;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    int saved[202][202];
    
    bool isValid(int i, int j) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    }
    
    int solve(vector<vector<int>>& matrix, int i, int j) {
        if(saved[i][j] != 0) return saved[i][j]; 
        int ans = 0;
        for(int k = 0 ; k < 4 ; k++) {
            int ii = i + di[k], jj = j + dj[k];
            if(isValid(ii, jj) && matrix[ii][jj] > matrix[i][j]) {
                ans = max(ans, solve(matrix, ii, jj));
            }
        }
        ans++;
        saved[i][j] = ans;
        return ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++) 
            for(int j = 0 ; j < m ; j++) 
                ans = max(ans, solve(matrix, i, j));
        
        return ans;
    }
};

