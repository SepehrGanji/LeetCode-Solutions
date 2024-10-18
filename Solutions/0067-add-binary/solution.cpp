class Solution {
public:
    string addBinary(string a, string b) {
        string small = b, big = a;
        if(a.length() < b.length()) small = a, big = b;
        string pad = "";
        for(int i = 0 ; i < big.length() - small.length() ; i++) pad += '0';
        small = pad + small;
        string ans = "";
        int carry = 0, n = big.length();
        for(int i = n - 1 ; i >= 0 ; i--) {
            int aa = (small[i] - '0'), bb = (big[i] - '0');
            int _ans = aa + bb + carry; carry = 0;
            if(_ans < 2) {
                ans = char('0'+_ans) + ans;
            } else {
                _ans -= 2;
                ans = char('0'+_ans) + ans;
                carry = 1;
            }
        }
        if(carry) ans = '1' + ans;
        return ans;
    }
};
