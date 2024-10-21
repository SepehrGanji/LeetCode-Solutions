class Solution {
public:
    int cnt[26];
    int ka;

    bool isValidWindow() {
        for(int i = 0 ; i < 26 ; i++) {
            if(cnt[i] >= ka) return true;
        }
        return false;
    }

    int numberOfSubstrings(string s, int k) {
        for(int i = 0 ; i < 26 ; i++) cnt[i] = 0;
        int n = s.length();
        ka = k;
        int l = 0, r = 0; cnt[s[0]-'a'] = 1;
        int ans = 0;
        while(r < n) {
            if(isValidWindow()) {
                ans += (n-r);
                cnt[s[l]-'a']--;
                l++;
                if(l > r) {
                    r = l;
                    if(r < n) cnt[s[r]-'a']++;
                }
            } else {
                r++;
                if(r < n) cnt[s[r]-'a']++;
            }
        }
        return ans;
    }
};
