class Solution {
public:
    string remove_digit(string s) {
        string ans = "";
        int i = 0;
        for( ; i < s.length() - 1 ; i++) {
            char ch = s[i];
            if(ch >= '0' && ch <= '9') {
                i++;
                break;
            }
            char ch2 = s[i+1];
            if(ch2 >= '0' && ch2 <= '9') {
                i+=2;
                break;
            }
            ans += ch;
        }
        for(; i < s.length() ; i++) ans += s[i];
        return ans;
    }

    string clearDigits(string s) {
        string ans = s;
        while(1) {
            string new_str = remove_digit(ans);
            if(ans == new_str) break;
            ans = new_str;
        }
        return ans;  
    }
};
