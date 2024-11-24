class Solution {
public:
    int dp[101][101][101];
int sfx_sum[101];
int ka;

int dipi(vector<int>& nums, int i, int op1, int op2) {
    if(i >= nums.size()) return 0;
    if(dp[i][op1][op2] >= 0) return dp[i][op1][op2];
    if(op1 == 0 && op2 == 0) return sfx_sum[i];
    int mini = nums[i] + dipi(nums, i+1, op1, op2);
    if(op1 > 0) {
        int el = nums[i] % 2 == 0 ? nums[i]/2 : (nums[i]+1)/2;
        mini = min(mini, el + dipi(nums, i+1, op1-1, op2));
    }
    if(op2 > 0 && nums[i] >= ka) {
        // do -k
        mini = min(mini, nums[i]-ka+dipi(nums, i+1, op1, op2-1));
    }
    if(op1 > 0 && op2 > 0 && nums[i] >= ka) {
        int el = nums[i] % 2 == 0 ? nums[i]/2 : (nums[i]+1)/2;
        if(el >= ka) {
            mini = min(mini, el-ka+dipi(nums, i+1, op1-1, op2-1));
        } else {
            int hello = nums[i] - ka;
            el = hello % 2 == 0 ? hello/2 : (hello+1)/2;
            mini = min(mini, el+dipi(nums, i+1, op1-1, op2-1));
        }
    }
    return dp[i][op1][op2] = mini;
}

int minArraySum(vector<int>& nums, int k, int op1, int op2) {
    int n = nums.size();
    ka = k;
    sort(nums.begin(), nums.end(), greater<>());
    sfx_sum[n-1] = nums[n-1];
    for(int i = n - 2 ; i >= 0 ; i--) sfx_sum[i] = sfx_sum[i+1] + nums[i];
    for(int i = 0 ; i < 101 ; i++)
        for(int j = 0 ; j < 101 ; j++)
            for(int k = 0 ; k < 101 ; k++)
                dp[i][j][k] = -1;
    
    return dipi(nums, 0, op1, op2);
}
};
