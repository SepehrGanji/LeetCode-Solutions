class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int j = 0, curr = 0;
    int ans = INT_MAX;
    for(int i = 0 ; i < nums.size() ; i++) {
        curr += nums[i];
        if(curr < target) continue;
        if(j <= i) {
            curr -= (nums[j] + nums[i]);
            ans = min(ans, i-j+1);
            j++;i--;
        }
    }
    if(ans == INT_MAX) ans = 0;
    return ans;
}
};
