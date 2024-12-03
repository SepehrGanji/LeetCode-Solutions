class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        spaces.push_back(3e5+5);
        string ans = "";
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < s.length()) {
            if(spaces[ptr2] == ptr1) {
                ans += ' ';
                ptr2++;
            } else {
                ans += s[ptr1];
                ptr1++;
            }
        }
        return ans;
    }
};
