class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        bool skip = false;
        vector<int> ans;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0 ; i < n ; i++) {
            if(i % 2 == 0) {
                for(int j = 0 ; j < m ; j++) {
                    if(!skip) ans.push_back(grid[i][j]);
                    skip = !skip;
                }
            } else {
                for(int j = m-1 ; j >= 0 ; j--) {
                    if(!skip) ans.push_back(grid[i][j]);
                    skip = !skip;
                }
            }
        }
        return ans;
    }
};
