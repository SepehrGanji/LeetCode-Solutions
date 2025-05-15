class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        bool pr = groups[0];
        vector<string> ans;
        ans.push_back(words[0]);
        int n = words.size();
        for(int i = 0 ; i < n ; i++) {
            if(groups[i] != pr) {
                pr = 1 - pr;
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
