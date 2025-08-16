class Solution {
public:
    string num2s(int n) {
        string ans = "";
        while(n > 0) {
            int d = n % 10;
            n /= 10;
            ans = char('0' + d) + ans;
        }
        return ans;
    }

    int s2num(string s) {
        int ans = 0;
        for(auto ch: s) {
            int d = ch-'0';
            ans *= 10;
            ans += d;
        }
        return ans;
    }

    int maximum69Number (int num) {
        string mmd = num2s(num);
        bool used = false;
        string mm2 = "";
        for(auto ch: mmd) {
            if(ch == '6' && !used) {
                used = true;
                mm2 += '9';
            } else mm2 += ch;
        }
        return s2num(mm2);
    }
};
