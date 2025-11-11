class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnt;
        for(auto num: nums) cnt[num]++;
        cnt[0] = 0;
        int ans = 0;
        vector<int> uniq_arr;
        for(auto pi: cnt) uniq_arr.push_back(pi.first);
        int en = uniq_arr.size();
        int dp[en];
        for(int i = 0 ; i < en ; i++) dp[i] = 0;
        int i = 0;
        for(auto pi: cnt) {
            int num = pi.first, count = pi.second;
            if(i == 0) {
                dp[i] = num * count;
            } else {
                if(uniq_arr[i] == uniq_arr[i-1] + 1) {
                    if(i >= 2) {
                        dp[i] = max(num * count + dp[i-2], dp[i-1]);
                    } else {
                        dp[i] = max(num * count, dp[i-1]);
                    }
                } else {
                    dp[i] = num * count + dp[i-1];
                }
            }
            i++;
        }

        return dp[en-1];
    }
};
