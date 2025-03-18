class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> mp; int n = s.length();
        char ch1 = '.', ch2 = '.';
        int ans = 1;
        int l = 0, r = 1; 
        ch1 = s[0];
        mp[ch1] = 0;
        while(r < n) {
            //r is the next candidate
            if(s[r] == ch1 || s[r] == ch2) {
                ans = max(ans, r-l+1);
                mp[s[r]] = r;
                r++;
            } else if(ch2 == '.') {
                ch2 = s[r];
                mp[ch2] = r;
                ans = max(ans, r-l+1);
                r++;
            } else {
                if(mp[ch1] < mp[ch2]) {
                    // get rid of ch1
                    l = mp[ch1] + 1;
                    ch1 = s[r];
                    mp[ch1] = r;
                    ans = max(ans, r-l+1);
                    r++;
                } else {
                    // get rid of ch2
                    l = mp[ch2] + 1;
                    ch2 = s[r];
                    mp[ch2] = r;
                    ans = max(ans, r-l+1);
                    r++;
                }
            }
        }
        return ans;
    }
};
