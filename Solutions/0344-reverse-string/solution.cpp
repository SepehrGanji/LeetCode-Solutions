class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            swap(s[l], s[r]);
            // int el = s[l], ar = s[r];
            // s[l] = ar;
            // s[r] = el;
            l++, r--;
        }
    }
};
