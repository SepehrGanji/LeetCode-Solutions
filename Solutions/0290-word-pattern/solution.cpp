class Solution {
public:
    bool wordPattern(string pattern, string s) {
    stringstream str(s);
    string word;
    map<string, char> mp1;
    map<char, string> mp2;
    int i = 0;
    while(str >> word) {
        if(i >= pattern.length()) return false;

        char c = pattern[i];
        if(mp1.find(word) != mp1.end()) {
            // found it
            if(mp1[word] != c) return false;
        } else mp1[word] = c;
        if(mp2.find(c) != mp2.end()) {
            // found it
            if(mp2[c] != word) return false;
        } else mp2[c] = word;
        i++;
    }
    if(i < pattern.length()) return false;
    return true;
}
};
