class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> seg(n, 0);
        vector<bool> ans;
        // int ai = 0;
        for(int i = 1 ; i < n ; i++) {
            if(nums[i] % 2 != nums[i-1] % 2) seg[i] = seg[i-1];
            else {
                seg[i] = seg[i-1] + 1; 
            }
        }
        for(auto qq: queries) {
            int a = qq[0], b = qq[1];
            ans.push_back(seg[a] == seg[b]);
        }
        return ans;
    }
};
