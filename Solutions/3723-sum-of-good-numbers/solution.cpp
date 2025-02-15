class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            bool good = true;
            if(i-k >= 0) if(nums[i] <= nums[i-k]) good = false;
            if(i+k < nums.size()) if(nums[i] <= nums[i+k]) good = false;
            if(good) ans += nums[i];
        }
        return ans;
    }
};
