class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        int i = 0; string word;
        while (ss >> word) {
            if(i >= pattern.length()) return false;
            char ch = pattern[i];
            if(mp.find(ch) == mp.end() && mp2.find(word) == mp2.end()) {
                mp[ch] = word;
                mp2[word] = ch;
            } else {
                if(mp.find(ch) == mp.end() || mp2.find(word) == mp2.end()) return false;
                if(mp[ch] != word || mp2[word] != ch) return false;
            }
            // else if(mp[ch] != word) return false;
            i++;
        }
        if(i < pattern.length()) return false;
        return true;
    }
};
