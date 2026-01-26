class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int l = 0, r = n;
        while(l < r) {
            int mid = (l+r)/2;
            if(nums[mid] == nums[mid+1]) {
                if(mid % 2 == 0) l = mid+2;
                else r = mid-1;
            } else if(nums[mid] == nums[mid-1]) {
                mid--;
                if(mid % 2 == 0) l = mid+2;
                else r = mid-1;
            } else return nums[mid];
        }
        return nums[l];
    }
};
