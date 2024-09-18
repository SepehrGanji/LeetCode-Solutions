class Solution {
public:
    bool isSubsequence(string s, string t) {
    int ptr = 0;
    for(int i = 0 ; i < t.length() ; i++) {
        if(ptr >= s.length()) break;
        if(s[ptr] == t[i]) ptr++;
    }
    return ptr >= s.length();
}
};
