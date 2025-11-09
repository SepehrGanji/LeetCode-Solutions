class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) maxi = max(maxi, nums[i]);
        int ans = 0;
        for(auto el: nums) ans += maxi-el;
        return ans;
    }
};
