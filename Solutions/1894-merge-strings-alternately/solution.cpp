class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        bool turn = true;
        int n1 = word1.length(), n2 = word2.length();
        int i1 = 0, i2 = 0;
        while(i1 < n1 && i2 < n2) {
            if(turn) {
                ans += word1[i1++];
            } else {
                ans += word2[i2++];
            }
            turn = !turn;
        }
        while(i1 < n1) ans += word1[i1++];
        while(i2 < n2) ans += word2[i2++];
        return ans;
    }
};
