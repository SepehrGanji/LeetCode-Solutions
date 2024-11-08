class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int n = word.length();
        int i = 0;
        while(i < n) {
            int ch = word[i++];
            int cnt = 1;
            while(i < n && word[i] == ch) {
                i++;
                cnt++;
            }
            ans += (cnt-1);
        }
        return ans;
    }
};
