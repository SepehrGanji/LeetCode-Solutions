class Solution {
public:
    bool isPalindrome(string s) {
    string str = "";
    for(int i = 0 ; i < s.length() ; i++) {
        char c = s[i];
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) str += c;
        if(c >= 'A' && c <= 'Z') str += 'a' + (c - 'A');
    }
    int lptr = 0, rptr = str.length()-1;
    while(lptr < rptr) {
        if(str[lptr] != str[rptr]) return false;
        lptr++, rptr--;
    }
    return true;
}
};
