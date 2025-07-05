class Solution {
public:
    vector<string> partitionString(string s) {
       unordered_map<string, bool> seen;
        vector<string> ans;
        string curr = "";
        for(auto ch: s) {
            curr += ch;
            if(seen.find(curr) == seen.end()) {
                ans.push_back(curr);
                seen[curr] = true;
                curr = "";
            }
        }
        return ans;
    }
};
