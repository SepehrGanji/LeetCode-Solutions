class Solution {
public:
    bool isIsomorphic(string s, string t) {
    map<char, char> mp;
    map<char, char> mp2;
    int n = s.length();
    for(int i = 0 ; i < n ; i++) {
        int cs = s[i], ct = t[i];
        if(mp.find(cs) != mp.end()) {
            if(mp[cs] != ct) return false;
        } else mp[cs] = ct;

        if(mp2.find(ct) != mp2.end()) {
            if(mp2[ct] != cs) return false;
        }else mp2[ct] = cs;
    }
    return true;
}
};
