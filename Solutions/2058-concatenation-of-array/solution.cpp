class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for(auto el: nums) ans.push_back(el);
        for(auto el: nums) ans.push_back(el);
        return ans;
    }
};
