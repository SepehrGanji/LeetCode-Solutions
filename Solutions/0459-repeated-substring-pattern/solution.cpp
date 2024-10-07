class Solution {
public:
    bool feas(int w, string &s) {
        int n = s.length();
        for(int j = w ; j < n ; j++) {
            if(s[j%w] != s[j]) return false;
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n == 1) return false;
        bool all_the_same = true;
        for(auto ch: s) if(ch != s[0]) {
            all_the_same = false;
            break;
        }
        if(all_the_same) return true;
        // window length
        for(int w = 2 ; w * w <= n ; w++) {
            if(n % w == 0) {
                if(feas(w, s)) return true;
                if(feas(n/w, s)) return true;
            }
        }
        return false;
    }
};
