class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        map<int, int> aa;
        map<int, int> bb;
        for(int i = 0 ; i < secret.length() ; i++) {
            if(secret[i] == guess[i]) a++;
            else {
                aa[secret[i]-'0']++;
                bb[guess[i]-'0']++;
            }
        }
        for(int d = 0 ; d < 10 ; d++) {
            b += min(aa[d], bb[d]);
        }
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
