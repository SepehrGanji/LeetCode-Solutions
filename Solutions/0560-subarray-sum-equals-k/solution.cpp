class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    map<int, int> mp;
    mp[0] = 1; 
    int n = nums.size();
    int sum_so_far = 0;
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        sum_so_far += nums[i];
        if(mp.find(sum_so_far-k) != mp.end()) {
            ans += mp[sum_so_far-k];
        }
        mp[sum_so_far]++;
    }
    return ans;
}
};
