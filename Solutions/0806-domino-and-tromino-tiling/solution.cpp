class Solution {
public:
    const int mod = 1e9 + 7;
    int numTilings(int n) {
        vector<long> f(1005, 0);
        vector<long> p(1005, 0);
        f[1] = 1; f[2] = 2;
        p[2] = 1;
        for(int i = 3 ; i <= n ; i++) {
            f[i] = ((f[i-1] + f[i-2]) % mod) + 2 * p[i-1];
            f[i] %= mod;
            p[i] = (p[i-1] + f[i-2]) % mod;
        }
        return f[n];
    }
};
