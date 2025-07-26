class Solution {
public:
    bool match(string s, int i, string b) {
        for(int j = 0 ; j < b.length() ; j++) {
            if(s[i+j] != b[j]) return false;
        }
        return true;
    }
    
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, pair<string, string>>> mmd;
        for(int i = 0 ; i < indices.size() ; i++) {
            mmd.push_back({indices[i], {sources[i], targets[i]}});
        }
        sort(mmd.begin(), mmd.end());
        for(int i = 0 ; i < indices.size() ; i++) {
            indices[i] = mmd[i].first;
            sources[i] = mmd[i].second.first;
            targets[i] = mmd[i].second.second;
        }
        string ans = "";
        int n = s.length();
        int j = 0;
        for(int i = 0 ; i < n ;) {
            bool mch = false;
            while (j < indices.size() && i == indices[j]) {
                if(match(s, i, sources[j])) {
                    // YAY
                    for(auto ch: targets[j]) ans += ch;
                    i += sources[j].length();
                    mch = true;
                }
                j++;
            }
            if(!mch) {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};
