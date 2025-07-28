class Solution {
public:
    int ans, maxi, n;

    void bt(vector<int>& nums, int idx, int curr) {
        if(idx == n) {
            if(curr == maxi) ans++;
            return;
        }
        bt(nums, idx+1, curr);
        bt(nums, idx+1, curr|nums[idx]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        for(auto el: nums) maxi |= el;
        bt(nums, 0, 0);
        return ans;
    }
};
