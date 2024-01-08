class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s.length() <= 1) return s.length();
    int l = 0, r = 1;
    int mp[1000];
    for(int i = 0 ; i < 1000 ; i++) mp[i] = -1;
    mp[s[l]] = 1; int ans = 1;
    while(r < s.length()) {
        int rchar = s[r];
        if(mp[rchar] - 1 >= l) {
            // char exists before
            l = mp[rchar];
            mp[rchar] = r + 1;
        } else {
            // char does not exist, safe to add
            mp[rchar] = r + 1;
            int cur_ans = r - l + 1;
            ans = max(ans, cur_ans);
        }
        r++;
    }
    return ans;
}
};
