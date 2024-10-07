class Solution {
public:
    pair<int, int> peak(vector<int>& nums, int l, int r) {
        if(l == r) return make_pair(nums[l], l);
        if(l == r-1) {
            if(nums[l] > nums[r]) {
                return make_pair(nums[l], l);
            } else {
                return make_pair(nums[r], r);
            }
        }
        int mid = (l + r) / 2;
        auto l_peak = peak(nums, l, mid);
        auto r_peak = peak(nums, mid+1, r);
        if(l_peak.first > r_peak.first) return l_peak;
        return r_peak;
    }
    
    int findPeakElement(vector<int>& nums) {
        return peak(nums, 0, nums.size() - 1).second;
    }
};
