class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int dp[2525];
      int n = nums.size();
      for(int i = 0 ; i < n ; i++) dp[i] = 1;
      for(int i = 1 ; i < n ; i++) {
        int maxim = 1;
        for(int j = 0 ; j < i ; j++) {
          if(nums[j] < nums[i] && dp[j] + 1 > maxim) 
            maxim = dp[j] + 1;
        }
        dp[i] = maxim;
      }

      return *max_element(dp, dp+n);
    }
};
