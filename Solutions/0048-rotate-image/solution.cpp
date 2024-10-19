class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transfer
        for(int d = 0 ; d < n ; d++) {
            for(int i = d+1 ; i < n ; i++) {
                swap(matrix[i][d], matrix[d][i]);
            }
        }
        // swap cols
        int c1 = 0, c2 = n-1;
        while(c1 < c2) {
            for(int i = 0 ; i < n ; i++) {
                swap(matrix[i][c1], matrix[i][c2]);
            }
            c1++, c2--;
        }
    }
};
