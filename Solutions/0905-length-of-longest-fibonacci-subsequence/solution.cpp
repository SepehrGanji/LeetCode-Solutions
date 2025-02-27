class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++) mp[arr[i]] = i;
        for(int j = 0 ; j < n ; j++) {
            for(int i = 0 ; i < j ; i++) {
                int diff = arr[j] - arr[i];
                if(mp.find(diff) == mp.end()) {
                    dp[i][j] = 2;
                } else {
                    if(diff < arr[i]) dp[i][j] = dp[mp[diff]][i] + 1;
                    else dp[i][j] = 2;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        if(ans > 2) return ans;
        return 0;
    }
};
