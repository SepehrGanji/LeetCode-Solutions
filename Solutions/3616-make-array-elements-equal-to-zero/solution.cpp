class Solution {
public:
    // true -> right, false -> left
    bool valid(vector<int> nums, int idx, bool dir) {
        int cnt = dir ? 1 : -1;
        int n = nums.size();
        while(idx >= 0 && idx < n) {
            if(nums[idx] > 0){
                nums[idx]--;
                cnt = cnt == 1 ? -1 : 1;
            }
            idx += cnt;
        }
        for(int i = 0 ; i < nums.size() ; i++) if(nums[i] != 0) return false;
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int ans = 0; int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 0) {
                ans += valid(nums, i, true);
                ans += valid(nums, i, false);
            }
        }
        return ans;
    }
};
