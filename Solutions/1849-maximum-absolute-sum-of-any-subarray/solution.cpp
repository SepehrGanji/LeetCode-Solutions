class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxpfx = 0, minpfx = 0;
        int pfx = 0;
        for(auto el: nums) {
            pfx += el;
            maxpfx = max(pfx, maxpfx);
            minpfx = min(pfx, minpfx);
        }
        return maxpfx - minpfx;
    }
};
