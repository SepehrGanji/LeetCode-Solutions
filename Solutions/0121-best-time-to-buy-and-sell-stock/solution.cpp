class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = 0;
        for(int i = 1 ; i < prices.size() ; i++) {
            int prof = prices[i] - mini;
            ans = max(prof, ans);
            mini = min(prices[i], mini);
        }
        return ans;
    }
};
