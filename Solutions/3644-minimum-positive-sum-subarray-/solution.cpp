class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0 ; i <= n - l ; i++) {
            int su = 0;
            for(int j = i ; j < i + l ; j++) su += nums[j];
            int mini = INT_MAX;
            if(su > 0) mini = su;
            for(int j = i + l ; j < min(n, i + r) ; j++) {
                su += nums[j];
                if(su > 0) mini = min(mini, su);
                // mini = min(mini, min(0, su));
            }
            ans = min(ans, mini);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
