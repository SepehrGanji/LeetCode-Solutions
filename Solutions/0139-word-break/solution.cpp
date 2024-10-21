class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp;
        for(int i = 0 ; i < n ; i++) dp.push_back(false);
        for(int i = 0 ; i < n ; i++) {
            for(auto word: wordDict) {
                int wlen = word.length();
                //int magic_num = i-wlen;
                if(i-wlen >= 0 && dp[i-wlen]) {
                    // base confirmed, now build
                    string sf = "";
                    for(int j = i-wlen+1 ; j <= i ; j++) sf += s[j];
                    if(sf == word) {
                        dp[i] = true;
                        break;
                    }
                } else if(i == wlen-1) {
                    // no base, but still build
                    string sf = "";
                    for(int j = 0 ; j <= i ; j++) sf += s[j];
                    if(sf == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n-1];
    }
};
