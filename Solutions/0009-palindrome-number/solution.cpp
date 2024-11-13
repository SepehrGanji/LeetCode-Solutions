class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long xback_up = x;
        long long new_x = 0;
        while(x > 0) {
            new_x *= 10;
            new_x += (x % 10);
            x /= 10;
        }
        return xback_up == new_x;
    }
};
