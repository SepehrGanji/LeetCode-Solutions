class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxim = 0, n = nums.size();
        for(auto el: nums) maxim = max(maxim, el);
        int ans = 1;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == maxim) {
                int local_ans = 1;
                int j = i+1;
                while(j < n && nums[j] == maxim) {
                    j++;
                    local_ans++;
                }
                ans = max(ans, local_ans);
                i = j-1;
            }
        }
        return ans;
    }
};

