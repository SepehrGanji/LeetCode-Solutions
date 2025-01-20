class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string str11, str22;
        if(str1.length() > str2.length()) {
            str11 = str2;
            str22 = str1;
        } else {
            str11 = str1;
            str22 = str2;
        }
        int l1 = str11.length(), l2 = str22.length();
        string ans = "";
        string curr_ans = "";
        for(int i = 0 ; i < l1 ; i++) {
            curr_ans += str11[i];
            if(l2 % (i+1) == 0 && l1 % (i+1) == 0) {
                bool mmd = true;
                for(int j = 0 ; j < l1 ; j++) {
                    if(curr_ans[j%(i+1)] != str11[j]) mmd = false;
                }
                for(int j = 0 ; j < l2 ; j++) {
                    if(curr_ans[j%(i+1)] != str22[j]) mmd = false;
                }
                if(mmd) ans = curr_ans;
            }
        }
        return ans;
    }
};
