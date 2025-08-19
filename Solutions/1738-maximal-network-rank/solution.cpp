class Solution {
public:
    bool gr[110][110];
    int deg[110];

    int solve(int a, int b) {
        int ans = deg[a] + deg[b];
        if(gr[a][b]) ans--;
        return ans;
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for(auto ro: roads) {
            int a = ro[0], b = ro[1];
            gr[a][b] = 1;
            gr[b][a] = 1;
            deg[a]++;
            deg[b]++;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = i+1 ; j < n ; j++)
                ans = max(ans, solve(i, j));
        
        return ans;
    }
};
