class Solution {
public:
    int prod_di(int x) {
        int prod = 1;
        while(x > 0) {
            prod *= (x % 10);
            x /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        while(1) {
            if(prod_di(ans) % t == 0) return ans;
            ans++;
        }
    }
};
