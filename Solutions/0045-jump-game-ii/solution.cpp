class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = max(nums[i] + i, nums[i - 1]);
        }
        
        int currentIndex = 0;
        int jumps = 0;
        
        while (currentIndex < nums.size() - 1) {
            jumps++;
            currentIndex = nums[currentIndex];
        }
        
        return jumps;
    }
};
