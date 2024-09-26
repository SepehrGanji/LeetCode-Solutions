class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string current_word = "";
        s += ' ';
        for(auto ch: s) {
            if(ch == ' ') {
                if(current_word != "") {
                    words.push_back(current_word);
                    current_word = "";
                }
                continue;
            }
            current_word += ch;
        }
        string ans = "";
        for(int i = words.size()-1 ; i >= 0 ; i--) {
            ans += words[i];
            if(i > 0) ans += ' ';
        }
        return ans;
    }
};
