class Solution {
public:
    string findValidPair(string s) {
        map<int, int> mp;
        int n = s.length();
        for(int i = 0 ; i < n ; i++) mp[s[i] - '0']++;
        for(int i = 1 ; i < n ; i++) {
            int a = s[i-1] - '0';
            int b = s[i] - '0';
            if(a != b) {
                if(mp[a] == a && mp[b] == b) {
                    string ans;
                    ans += ('0' + a);
                    ans += ('0' + b);
                    return ans;
                }
            }
        }
        return "";
    }
};
