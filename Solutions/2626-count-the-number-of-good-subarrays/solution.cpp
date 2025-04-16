class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int sam = 0, r = -1;
        unordered_map<int, int> mp;
        for(int l = 0 ; l < n ; l++) {
            while(sam < k && r + 1 < n) {
                r++;
                sam += mp[nums[r]];
                mp[nums[r]]++;
            }
            if(sam >= k) {
                ans += (n - r);
            }
            mp[nums[l]]--;
            sam -= mp[nums[l]];
        }
        return ans;
    }
};
