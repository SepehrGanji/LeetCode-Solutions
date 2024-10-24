class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string raw = "";
        for(auto ch: s) if(ch != '-') {
            if(ch >= 'a' && ch <= 'z') raw += 'A' + (ch - 'a');
            else raw += ch;
        }
        int n = raw.length();
        int off = 0;
        string ans = "";
        if(n % k > 0) {
            int m = n % k;
            while(off < m) ans += raw[off++];
            if(off < n) ans += '-';
        }
        for(int i = 0 ; i+off < n ; i++) {
            ans += raw[i+off];
            if((i+1) % k == 0 && i+off != n-1) ans += '-';
        }
        
        return ans;
    }
};
