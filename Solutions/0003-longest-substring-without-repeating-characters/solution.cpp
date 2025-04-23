class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int ans = 1;
        vector<int> mp(1000, -1);
        int l = 0, r = 1; // r is the next candidate
        mp[s[0]] = 0;
        while(r < s.length()) {
            if(mp[s[r]] < l) {
                // OK to add
                ans = max(ans, r-l+1);
            } else {
                // not OK to add
                l = mp[s[r]] + 1;
                ans = max(ans, r-l+1);
            }
            mp[s[r]] = r;
            r++;
        }
        return ans;
    }
};
