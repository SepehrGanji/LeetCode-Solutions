class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }
        unordered_map<char, int> dictT;
        for (int i = 0; i < t.length(); i++) {
            dictT[t[i]]++;
        }
        int required = dictT.size();
        int l = 0, r = 0;
        int formed = 0;
        unordered_map<char, int> windowCounts;
        int ans[3] = {-1, 0, 0};
        while (r < s.length()) {
            char c = s[r];
            windowCounts[c]++;
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                formed++;
            }
            while (l <= r && formed == required) {
                c = s[l];
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }
                windowCounts[c]--;
                if (dictT.find(c) != dictT.end() &&
                    windowCounts[c] < dictT[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};
