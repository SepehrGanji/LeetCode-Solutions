class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p1 = 0, p2 = nums.size();
        while(p1 < p2) {
            if(nums[p1] == val) {
                swap(nums[p1], nums[p2-1]);
                p2--;
            } else p1++;
        }
        return p1;
    }
};
