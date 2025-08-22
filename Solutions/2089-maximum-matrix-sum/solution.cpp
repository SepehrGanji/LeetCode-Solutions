class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        vector<int> ali;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                ali.push_back(abs(matrix[i][j]));
                if(matrix[i][j] < 0) cnt++;
            }
        }
        sort(ali.begin(), ali.end());
        if(cnt % 2 == 1) ali[0] *= -1;
        for(auto el: ali) ans += el;
        return ans;
    }
};
