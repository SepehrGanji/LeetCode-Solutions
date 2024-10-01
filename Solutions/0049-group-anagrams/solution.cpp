class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto str: strs) {
            string sss = str;
            sort(sss.begin(), sss.end());
            mp[sss].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto pii: mp) {
            ans.push_back(pii.second);
        }
        return ans;
    }
};
