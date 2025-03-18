class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool rev = true;
        int n = nums.size();
        for(int i = 0 ; i < n-1 ; i++) if(nums[i] < nums[i+1]) rev = false;
        if(rev) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int pvt_point = -1;
        int el = nums[n-1];
        int ptr = n-2;
        while(pvt_point == -1) {
            if(nums[ptr] < el) {
                pvt_point = ptr;
            } else {
                el = nums[ptr];
                ptr--;
            }
        }
        int swp_point = -1;
        ptr = n-1;
        while(swp_point == -1) {
            if(nums[ptr] > nums[pvt_point]) {
                swp_point  = ptr;
            } else ptr--;
        }
        swap(nums[swp_point], nums[pvt_point]);
        reverse(nums.begin()+pvt_point+1, nums.end());
    }
};
