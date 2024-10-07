class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str = "";
        for(auto ch: s) {
            if(ch != '-') {
                if(ch >= 'a' && ch <= 'z') {
                    str += ('A' + (ch - 'a'));
                } else str += ch;
            }
        }
        string ans = "";
        int rem = str.length() % k;
        if(rem > 0) {
            for(int i = 0 ; i < rem ; i++) ans += str[i];
            if(str.length() > rem) ans += '-';
        }
        for(int i = 0 ; i < str.length() - rem ; i++) {
            ans += str[rem+i];
            if(i < str.length() - rem-1 && i % k == k-1) ans += '-';
        }
        return ans;
    }
};
