class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  map<int, int> mp;
  for(int i = 0 ; i < nums.size() ; i++) {
    if(mp[nums[i]] > 0) {
      vector<int> ans = {mp[nums[i]]-1, i};
      return ans;
    }
    mp[target - nums[i]] = i + 1;
  }
  return {};
}
};
