class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        for(auto ch: s) {
            if(ch == 'A') cnt++;
        }
        if(cnt >= 2) return false;
        int n = s.length();
        for(int i = 0 ; i < n - 2 ; i++) {
            if(s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L') return false;
        }
        
        return true;
    }
};
