class Solution {
public:
    string ans;
    bool solve(vector<char>& path,vector<int>& cnt, string & target, bool big) {
        int n = target.size();
        if(ans != "") return true;

        if(path.size() == n) {
            if(big) {
                ans = string(path.begin(), path.end());
                return true;
            }
            return false;
        }
        int i = path.size();
        for(int c = 0 ; c < 26 ; c++) {
            if(cnt[c] == 0) continue;
            if(!big && c < target[i]-'a') continue;
            path.push_back(c+'a');
            cnt[c]--;
            bool newbig = big || (c > target[i] -'a');
            if(solve(path, cnt, target, newbig)) return true;
            path.pop_back();
            cnt[c]++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for(auto ch: s) cnt[ch-'a']++;
        vector<char> path;
        solve(path, cnt, target, false);
        return ans;
    }
};
