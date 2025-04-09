class Solution {
public:
    bool isGood(int n) {
        bool yay = false;
        while(n > 0) {
            int dig = n % 10;
            if(dig == 3 || dig == 4 || dig == 7) return false;
            if(dig == 2 || dig == 5 || dig == 6 || dig == 9) yay = true;
            n /= 10;
        }
        return yay;
    }
    
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1 ; i <= n ; i++) ans += isGood(i);
        return ans;
    }
};
