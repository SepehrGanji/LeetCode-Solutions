class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        for(auto num: nums) {
            mp[num]++;
            if(mp[num] == 2) ans.push_back(num);
        }
        return ans;
    }
};
