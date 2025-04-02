class Solution {
public:
    long long dp[100000+10];

    long long dipi(vector<vector<int>>& questions, int i) {
        int n = questions.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long ans = 0;
        ans = max(questions[i][0] + dipi(questions, i+1+questions[i][1]), dipi(questions, i+1));
        return dp[i] = ans;
    }    

    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        return dipi(questions, 0);
    }
};
