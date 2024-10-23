class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n];
        if(s[0] == '0') return 0;
        dp[0] = 1;
        for(int i = 1 ; i < n ; i++) {
            char curr = s[i];
            // check if i can be on my own
            if(curr != '0') {
                // OWN OK
                dp[i] = dp[i-1];
                if(s[i-1] == '1') {
                    if(i < 2) dp[i]++;
                    else dp[i] += dp[i-2];
                } else if(s[i-1] == '2' && curr < '7') {
                    if(i < 2) dp[i]++;
                    else dp[i] += dp[i-2];
                }
            } else {
                if(s[i-1] > '2' || s[i-1] == '0') return 0;
                // I'm dependent as hell
                if(i < 2) dp[i] = 1;
                else dp[i] = dp[i-2];
            }
        }
        return dp[n-1];
    }
};
