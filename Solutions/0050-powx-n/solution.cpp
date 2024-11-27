class Solution {
public:
    double myPow(double x, int n) {
        //if(x == 1) return 1;
        long long en = n;
        if(n < 0) {
            x = 1/x;
            en = -1ll * n;
        }
        if(en == 0) return 1;
        if(en % 2 == 0) 
            return myPow(x*x, en/2);
        else
            return x*myPow(x*x, (en-1)/2);
    }
};
