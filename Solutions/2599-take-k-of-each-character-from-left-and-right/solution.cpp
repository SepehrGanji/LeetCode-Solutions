class Solution {
public:
    bool isValid(vector<int>& total, vector<int>& so_far, int k) {
        for(int i = 0 ; i < 3 ; i++) if(total[i] - so_far[i] < k) return false;
        return true;
    }
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        vector<int> total(3, 0);
        for(auto ch: s) total[ch-'a']++;
        for(int i = 0 ; i < 3 ; i++) if(total[i] < k) return -1;
        vector<int> so_far(3, 0);
        int l = 0, r = 0;
        int ans = 0;
        while(r < s.length()) {
            so_far[s[r]-'a']++;
            while(!isValid(total, so_far, k)) {
                so_far[s[l]-'a']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
            // if(isValid(total, so_far, k)) r++;
            // else {
            //     ans = max(ans, r-l);
            //     so_far[0] = so_far[1] = so_far[2] = 0;
            //     // slide it!
            //     r++;
            //     l = r;
            // }
        }
        return s.length() - ans;
    }
};
