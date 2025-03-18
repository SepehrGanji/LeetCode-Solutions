class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        int to_cover = lower;
        int n = nums.size();
        int idx = 0;
        while(idx < n) {
            int el = nums[idx];
            if(to_cover < el) {
                ans.push_back({to_cover, el-1});
                to_cover = el;
            } else {
                // to_cover == el
                to_cover++;
                idx++;
            }
        }

        if(n > 0 && nums[n-1] < upper) {
            ans.push_back({nums[n-1]+1, upper});
        }
        if(n == 0) {
            ans.push_back({lower, upper});
        }
        return ans;
    }
};
