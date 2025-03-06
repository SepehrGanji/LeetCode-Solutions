class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr((n*n)+1, 0);
        vector<int> ans = {0, 0};
        for(int i = 0 ; i < n ; i++) 
            for(int j = 0 ; j < n ; j++) arr[grid[i][j]]++;
        for(int i = 1 ; i <= n*n ; i++)
                if(arr[i] == 2) ans[0] = i;
                else if(arr[i] == 0) ans[1] = i;
            
        return ans;
    }
};
