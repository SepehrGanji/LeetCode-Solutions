class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.length(), m = typed.length();
        int ptr = 0;
        for(int i = 0 ; i < n ; i++) {
            if(name[i] != typed[ptr]) return false;
            ptr++;
            if(i == n-1) {
                while(ptr < m) {
                    if(typed[ptr] != name[i]) return false;
                    ptr++;
                }
            } else {
                while(typed[ptr] == name[i] && typed[ptr] != name[i+1]) {
                    ptr++;
                    if(ptr == m) break;
                }
            }
        }
        return true;
    }
};
