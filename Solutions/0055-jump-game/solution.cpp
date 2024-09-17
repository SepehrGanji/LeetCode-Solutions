class Solution {
public:
    bool canJump(vector<int>& nums) {
    int cov = 0;
    int i = 0;
    int n = nums.size();
    while(cov < n-1 && i < nums.size()) {
        if(cov < i) return false;
        cov = max(cov, i + nums[i]);
        i++;
    }
    return cov >= n-1;
}
};
