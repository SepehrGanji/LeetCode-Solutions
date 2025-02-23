class Solution {
private:
    int choose[5][5];
    int mod5(int n, int k) {
        int res = 1;
        while(n > 0 || k > 0) {
            int n_digit = n % 5;
            int k_digit = k % 5;
            if(k_digit > n_digit)
                return 0;
            res = (res * choose[n_digit][k_digit]) % 5;
            n /= 5;
            k /= 5;
        }
        return res;
    }
    int mod2(int n, int k) {
        if((k & (~n)) == 0) return 1;
        return 0;
    }
    int coef(int n, int k) {
        int a = mod2(n, k);
        int b = mod5(n, k);
        return (5*a + 6*b) % 10;
    }    
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        for(int i = 0 ; i < 5 ; i++) {
            for(int j = 0 ; j <= i ; j++) {
                if(j == 0 || j == i) choose[i][j] = 1;
                else choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % 5;
            }
        }
        int ld = 0, rd = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            int co = coef(n-2, i);
            int A = s[i] - '0';
            int B = s[i+1] - '0';
            ld = (ld + co * A) % 10;
            rd = (rd + co * B) % 10;
        }
        return ld == rd;
    }
};
