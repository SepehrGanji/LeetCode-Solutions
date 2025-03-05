class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0;
        int cent = 2*n - 1;
        ans -= cent;
        while(cent > 0) {
            ans += (2*cent);
            cent -= 2;
        }
        return ans;
    }
};
