class Solution {
public:
    int add(int a) {
        int ans = 0;
        while(a > 0) {
            // ans *= 10;
            ans += (a % 10);
            a /= 10;
        }
        return ans;
    }
    int addDigits(int num) {
        while(num != add(num)) num = add(num);
        return num;
    }
};
