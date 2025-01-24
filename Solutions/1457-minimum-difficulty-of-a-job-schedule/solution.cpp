class Solution {
public:
    int dp[305][15];
    int en, da;
    int jd[305];

    int dipi(int i, int d) {
        if(dp[i][d] != -1) return dp[i][d];
        int ans = INT_MAX;
        if(d == da) {
            ans = -1;
            for(int j = i ; j < en ; j++) ans = max(ans, jd[j]);
            return ans;
        } else {
            int max_so_far = 0;
            for(int j = i ; j < en - (da - d) ; j++) {
                max_so_far = max(max_so_far, jd[j]);
                ans = min(ans, max_so_far + dipi(j+1, d+1));
            }
        }
        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        for(int i = 0 ; i < 305 ; i++)
            for(int j = 0 ; j < 15 ; j++) dp[i][j] = -1;
        en = jobDifficulty.size(); da = d;
        if(da > en) return -1;
        for(int i = 0 ; i < en ; i++) jd[i] = jobDifficulty[i];
        return dipi(0, 1);
    }
};
