class Solution {
public:
    bool subsetsum(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(x+1, false));
        for(int i = 0 ; i <= n ; i++) dp[i][0] = true;
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= x ; j++) {
                int idx = i-1;
                if(j - nums[idx] >= 0) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[idx]];
                } else dp[i][j] = dp[i-1][j];
                
            }
        }

        return dp[n][x];
    }

    bool canPartition(vector<int>& nums) {
        int x = 0, n = nums.size();
        for(auto el: nums) x+= el;
        if(x % 2 == 1) return false;
        return subsetsum(nums, x/2);    
    }
};
