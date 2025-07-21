class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 0;
        char last = '?';
        for(auto ch: s) {
            if(ch != last) {
                cnt = 1;
                last = ch;
                ans += ch;
            } else {
                if(cnt < 2) {
                    cnt++;
                    ans += ch;
                }
            }
        }
        return ans;
    }
};
