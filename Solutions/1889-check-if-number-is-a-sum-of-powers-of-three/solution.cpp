class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n <= 1) return true;
        if(n % 3 == 2) return false;
        if(n % 3 == 1) n -= 1;
        while(n % 3 == 0) n /= 3;
        return checkPowersOfThree(n);
    }
};
