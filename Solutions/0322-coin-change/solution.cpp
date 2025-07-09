class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1, -1);
        ans[0] = 0;
        for(int i = 1 ; i <= amount ; i++) {
            int cur_min = INT_MAX;
            for(auto c: coins) {
                int idx = i - c;
                if(idx < 0) continue;
                if(ans[idx] == -1) continue;
                cur_min = min(cur_min, 1+ans[idx]);
            }
            if(cur_min < INT_MAX) ans[i] = cur_min;
        }
        for(int i = 0 ; i <= amount ; i++) cout << ans[i] << ' ';
        cout << endl;
        return ans[amount];
    }
};
