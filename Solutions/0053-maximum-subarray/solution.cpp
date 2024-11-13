class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1 ; i < n ; i++) {
            int el = nums[i];
            dp[i] = max(dp[i-1] + el, el);
        }
        int maxim = dp[0];
        for(int i = 1 ; i < n ; i++) {
            if(dp[i] > maxim) maxim = dp[i];
        }
        return maxim;
    }
};
