class Solution {
public:
    double epsilon = 1e-5;
    double check(vector<vector<int>>& squares, double vay) {
        double mass = 0;
        for(auto& sq: squares) {
            double x = sq[0], y = sq[1], len = sq[2];
            if(y >= vay) continue;
            if(y + len <= vay) {
                // complete zeer
                mass += (len*len);
            } else {
                // partial zeer
                mass += ((vay-y) * len);
            }
        }
        return mass;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        for(auto& sq: squares) total += ((double)sq[2] * sq[2]);
        double target = total / 2.0;
        double l = 0, r = 1e9;
        while(r - l > epsilon) {
            double mid = (l+r)/2.0;
            double ch = check(squares, mid);
            if(ch < target) l = mid;
            else r = mid;
        }
        return r;
    }
};
