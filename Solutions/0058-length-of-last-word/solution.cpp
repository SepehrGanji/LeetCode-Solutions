class Solution {
public:
    int lengthOfLastWord(string s) {
        s += ' ';
        int ans = 0;
        int curr = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            char c = s[i];
            if(c == ' ' && curr > 0) {
                ans = curr;
                curr = 0;
            }
            if(c == ' ') continue;
            curr++;
        }
        return ans;
    }
};
