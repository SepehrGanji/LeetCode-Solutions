class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pfx_max(n, nums[0]);
        vector<long long> sfx_max(n, nums[n-1]);

        for(int i = 1 ; i < n ; i++) pfx_max[i] = max(pfx_max[i-1], 1ll*nums[i]);
        for(int i = n-2 ; i >= 0 ; i--) sfx_max[i] = max(sfx_max[i+1], 1ll*nums[i]);
        long long ans = 0;
        for(int j = 1 ; j < n - 1 ; j++) ans = max(ans, (pfx_max[j-1] - nums[j]) * sfx_max[j+1]);
        return ans;
    }
};
