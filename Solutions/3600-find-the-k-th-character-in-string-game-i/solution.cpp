class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        while(str.length() < k) {
            string cpy = "";
            for(int i = 0 ; i < str.length() ; i++) {
                int ch = (str[i] - 'a');
                ch++;
                ch %= 26;
                cpy += ('a' + ch);
            }
            str += cpy;
        }
        //cout << str << endl;
        return str[k-1];
    }
};
