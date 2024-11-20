class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int curr_idx = 0;
        int i = 1; int n = nums.size();
        while(i < n) {
            if(nums[i] > nums[curr_idx]) {
                // jump!
                ans += nums[curr_idx] * (1ll * (i - curr_idx));
                curr_idx = i;
            }
            i++;
        }
        if(curr_idx < n-1) {
            ans += nums[curr_idx] * (1ll * (n-1 - curr_idx));
        }
        return ans;
    }
};
