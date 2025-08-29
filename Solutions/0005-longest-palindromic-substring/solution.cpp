class Solution {
public:
    bool dp[1010][1010];
    // string ans[1010][1010];
    pair<int, int> ans;

    string longestPalindrome(string s) {    
        int n = s.length();
        for(int i = 0 ; i < n ; i++) dp[i][i] = true;
        for(int i = 0 ; i < n-1 ; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ans = {i, i+1};
            }
            
        }

        for(int L = 2 ; L < n ; L++) {
            for(int i = 0 ; i < n - L ; i++) {
                int j = i + L;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};

