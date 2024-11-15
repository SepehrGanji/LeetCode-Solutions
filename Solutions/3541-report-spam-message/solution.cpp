class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        sort(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for(auto wd: message) {
            if(binary_search(bannedWords.begin(), bannedWords.end(), wd)) {
                cnt++;
            }
            if(cnt >= 2) break;
        }
        return cnt >= 2;
    }
};
