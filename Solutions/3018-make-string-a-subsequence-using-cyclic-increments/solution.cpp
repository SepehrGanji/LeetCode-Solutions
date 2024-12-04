class Solution {
public:
    bool match(char a, char b) {
        if(a == b) return true;
        if(a == 'z' && b == 'a') return true;
        if(a+1 == b) return true;
        return false;
    }

    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        if(m > n) return false;
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < n && ptr2 < m) {
            if(match(str1[ptr1], str2[ptr2])) {
                ptr2++;
            }
            ptr1++;
        }

        return ptr2 >= m;
    }
};
