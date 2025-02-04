class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, local_ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] <= nums[i-1]) {
                ans = max(ans, local_ans);
                local_ans = nums[i];
            } else local_ans += nums[i];
        }
        return max(ans, local_ans);
    }
};
