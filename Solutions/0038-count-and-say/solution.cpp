class Solution {
public:
    string RLE(string s) {
        string ans = "";
        char cur = s[0];
        int cnt = 1;
        for(int i = 1 ; i < s.length() ; i++) {
            if(s[i] == cur) cnt++;
            else {
                ans += ('0' + cnt);
                ans += cur;
                cur = s[i];
                cnt = 1;
            }
        }
        // Don't forget to add the last one
        ans += ('0' + cnt);
        ans += cur;
        return ans;
    }

    string countAndSay(int n) {
        string ans = "1";
        n--;
        while(n--) ans = RLE(ans);
        return ans;    
    }
};
