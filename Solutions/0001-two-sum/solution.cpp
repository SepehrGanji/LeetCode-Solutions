class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    map<int, int> mp;
    for(int i = 0 ; i < n ; i++) {
        int num = nums[i];
        if(mp.find(target-num) != mp.end()) {
            vector<int> ans = {mp[target-num], i};
            return ans;
        }
        mp[num] = i;
    }
    return {};
}
};
