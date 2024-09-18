class Solution {
public:
    int romanToInt(string s) {
    map<char, int> mp; int n = s.length();
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        int c = s[i];
        if(i == n-1) ans += mp[c];
        else {
            if(c == 'I' && s[i+1] == 'V') {
                ans += 4; i++;
            } else if(c == 'I' && s[i+1] == 'X') {
                ans += 9; i++;
            } else if(c == 'X' && s[i+1] == 'L') {
                ans += 40; i++;
            } else if(c == 'X' && s[i+1] == 'C') {
                ans += 90; i++;
            } else if(c == 'C' && s[i+1] == 'D') {
                ans += 400; i++;
            } else if(c == 'C' && s[i+1] == 'M') {
                ans += 900; i++;
            } else {
                ans += mp[c];
            }
        }
    }
    return ans;
}
};
