class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xo = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) xo ^= nums[i];
        return xo;
    }
};
