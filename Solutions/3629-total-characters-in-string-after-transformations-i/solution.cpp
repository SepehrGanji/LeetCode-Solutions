class Solution {
public:
    int mod = 1000000000 + 7;

    int lengthAfterTransformations(string s, int t) {
        int omp[26];
        int nmp[26];
        for(int i = 0 ; i < 26 ; i++) omp[i] = 0;
        for(auto ch: s) omp[ch-'a']++;
        while(t--) {
            for(int i = 0 ; i < 26 ; i++) nmp[i] = 0;
            for(int i = 0 ; i < 25 ; i++) {
                nmp[i+1] = omp[i];
            }
            nmp[0] += omp[25];
            nmp[1] += omp[25];
            for(int i = 0 ; i < 26 ; i++) omp[i] = nmp[i] % mod;
        }
        int ans = 0;
        for(auto el: omp) {
            ans += el;
            ans %= mod;
        }
        return ans;
    }
};
