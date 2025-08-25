class Solution {
public:
    long long gime(long long n) {
        long long ans = 0;
        long long m = 2 * n + 1;
        long long pad = 1;
        for(long long i = 0 ; i <= n ; i++) {
            ans += pad * i;
            pad++;
        }
        pad -= 2;
        for(long long i = n+1 ; i < m ; i++) {
            ans += pad * i;
            pad--;
        }
        ans *= 4;
        pad = 0;
        for(long long i = 0 ; i <= n ; i++) {
            pad += i;
        }
        ans -= pad*4;
        return ans;
    }

    long long minimumPerimeter(long long neededApples) {
        long long l = 0, r = 500000;
        while(l < r) {
            long long mid = (l+r)/2;
            if(gime(mid) >= neededApples) r = mid;
            else l = mid+1;
        }
        return (r)*8;
    }
};
