class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++) {
            sort(grid[i].begin(), grid[i].end());
            reverse(grid[i].begin(), grid[i].end());
        }
        priority_queue<int> pq;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < min(limits[i], m) ; j++) pq.push(grid[i][j]);
        }
        long long ans = 0;
        while(k--) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
