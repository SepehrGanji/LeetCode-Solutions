class Solution {
public:
    int dp[35][1005];
    const int mod = 1e9 + 7;
    int n, k;
    
    int dipi(int i, int tar) {
        if(i > n || tar < 0) return 0;
        if(i < n && tar == 0) return 0;
        if(i == n && tar == 0) return 1;
        if(i == n) return 0;
        if(dp[i][tar] != -1) return dp[i][tar];
        long ans = 0;
        for(int B = 1 ; B <= min(k, tar) ; B++) {
            ans += dipi(i+1, tar-B);
            ans %= mod;
        }
        return dp[i][tar] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        this->n = n;
        this->k = k;
        return dipi(0, target);
    }
};
