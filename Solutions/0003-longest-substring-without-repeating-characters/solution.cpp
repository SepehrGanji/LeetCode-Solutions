class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int mp[1000];
        for(int i = 0 ; i < 1000 ; i++) mp[i] = -1;
        int l = 0, r = 1;
        mp[s[0]] = 0;
        int ans = 1;
        while(r < s.length()) {
            // r is the next candidate
            if(mp[s[r]] >= l) {
                // can't, sorry, already seen!
                l = mp[s[r]] + 1;
                mp[s[r]] = r;
                ans = max(ans, r-l+1);
            } else {
                // add ittttttttttt
                mp[s[r]] = r;
                ans = max(ans, r-l+1);
            }
            r++;
        }
        
        return ans;
    }
};
