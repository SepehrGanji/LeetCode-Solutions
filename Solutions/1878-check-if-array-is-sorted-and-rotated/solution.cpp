class Solution {
public:
    bool check(vector<int>& nums) {
        bool hap = false; int n = nums.size();
        for(int i = 1 ; i < n ; i++) {
            if(nums[i] < nums[i-1]) {
                if(hap) return false;
                hap = true;
            }
        }
        if(hap) return nums[n-1] <= nums[0];
        return true;
    }
};
