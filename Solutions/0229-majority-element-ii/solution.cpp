class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto el: nums) mp[el]++;
        for(auto el: mp) {
            if(el.second > floor(n/3.0)) ans.push_back(el.first);
        }
        return ans;
    }
};
