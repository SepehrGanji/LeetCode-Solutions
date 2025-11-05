class Solution {
public:
    int d1, d2, h1, h2;
    long long lcm;

    bool poss(long long ans) {
        if(d1 + d2 > ans) return false;
        long long np1 = floor(ans/h1);
        long long np2 = floor(ans/h2);
        long long p1 = ans - np1;
        long long p2 = ans - np2;
        long long both_not_avail = floor(ans/lcm);
        long long both_avail = (p1+p2) - (ans-both_not_avail);
        p1 -= both_avail;
        p2 -= both_avail;
        long long dd1 = d1, dd2 = d2;
        dd1 -= p1;
        dd2 -= p2;
        dd1 = max(dd1, 0ll);
        dd2 = max(dd2, 0ll);
        return dd1+dd2 <= both_avail;
    }

    long long minimumTime(vector<int>& d, vector<int>& h) {
        d1 = d[0], d2 = d[1];
        h1 = h[0], h2 = h[1];
        lcm = (h1*h2) / __gcd(h1, h2);
        cout << lcm << endl;
        long long l = 0, r = 1e10;
        while(l < r) {
            long long mid = (l+r)/2;
            if(poss(mid)) r = mid;
            else l = mid+1;
        }
        return r;
    }
};

