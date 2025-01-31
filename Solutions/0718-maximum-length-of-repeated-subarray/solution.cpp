class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // row 0
        for(int j = 0 ; j < m ; j++) dp[0][j] = (nums1[0] == nums2[j]);
        // col 0
        for(int i = 1 ; i < n ; i++) dp[i][0] = (nums1[i] == nums2[0]);
        // the dp
        for(int i = 1 ; i < n ; i++)
            for(int j = 1 ; j < m ; j++)
                if(nums1[i] == nums2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++) ans = max(ans, dp[i][j]);
        return ans;
    }
};
