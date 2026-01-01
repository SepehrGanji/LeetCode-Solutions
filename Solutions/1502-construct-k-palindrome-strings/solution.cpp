class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(k > n) return false;
        if(k == n) return true;
        k--;
        unordered_map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        for(auto el: mp) {
            if(k == 0) break;
            if(el.second % 2 == 1) {
                k--;
                mp[el.first]--;
            }
        }
        int cnt = 0;
        for(auto el: mp) {
            if(el.second % 2 == 1) cnt++;
        }
        return cnt <= 1;
    }
};
