class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        for(int i = 0 ; i <= n-k ; i++) {
            if(i > 0 && s[i] == s[i-1]) continue;
            char ch = s[i]; bool yay = true;
            for(int j = i + 1 ; j < i + k ; j++) {
                if(s[j] != ch) yay = false;
            }
            if(i + k < n && s[i+k] == ch) yay = false;
            if(yay) return true;
        }
        return false;
    }
};
