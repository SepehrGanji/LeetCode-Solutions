class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string word; 
        int i = 0;
        while (s >> word) {
            i++;
            if(word.length() >= searchWord.length()) {
                bool yup = true;
                for(int i = 0 ; i < searchWord.length() ; i++) {
                    if(searchWord[i] != word[i]) {
                        yup = false;
                        break;
                    }
                }
                if(yup) return i;
            }
        }
        return -1;
    }
};
