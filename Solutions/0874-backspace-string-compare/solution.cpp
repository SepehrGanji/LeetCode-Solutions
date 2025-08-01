class Solution {
public:
    bool backspaceCompare(string s, string t) {
        while(s.length() < t.length()) s = '#' + s;
        while(t.length() < s.length()) t = '#' + t;
        int ska = 0, skb = 0;
        int ptra = s.length() - 1, ptrb = t.length() - 1;
        char tma = ' ';
        char tmb = ' ';
        while(ptra >= 0 && ptrb >= 0) {
            if(tma == ' ' && ptra >= 0) {
                // we still have something in a
                if(s[ptra] == '#') ska++, ptra--;
                else if(ska > 0) ska--, ptra--;
                else tma = s[ptra];
            }
            if(tmb == ' ' && ptrb >= 0) {
                // we still have something in b
                if(t[ptrb] == '#') skb++, ptrb--;
                else if(skb > 0) skb--, ptrb--;
                else tmb = t[ptrb];
            }
            if(tma != ' ' && tmb != ' ') {
                if(tma != tmb) return false;
                tma = ' ';
                tmb = ' ';
                ptra--;
                ptrb--;
            }
        }
        if(tma != ' ' || tmb != ' ') return false;
        while(ptra >= 0) {
            if(tma != ' ') return false;
            if(s[ptra] == '#') ska++, ptra--;
            else if(ska > 0) ska--, ptra--;
            else tma = s[ptra];
        }
        while(ptrb >= 0) {
            if(tmb != ' ') return false;
            if(t[ptrb] == '#') skb++, ptrb--;
            else if(skb > 0) skb--, ptrb--;
            else tmb = t[ptrb];
        }
        return true;
    }
};
