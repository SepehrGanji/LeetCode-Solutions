class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0 ; i < numRows ; i++) {
            int cnt = i+1;
            vector<int> local;
            local.resize(cnt);
            local[0] = local[cnt-1] = 1;
            for(int j = 1 ; j < cnt - 1 ; j++) {
                local[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(local);
        }
        return ans;
    }
};
