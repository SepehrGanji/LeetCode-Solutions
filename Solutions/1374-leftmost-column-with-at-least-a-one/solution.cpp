/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int n, m;
    
    int solve(int row, BinaryMatrix &binaryMatrix) {
        int l = 0, r = m;
        while(l < r) {
            int mid = (l+r)/2;
            if(binaryMatrix.get(row, mid)) r = mid;
            else l = mid+1;
        }
        if(r == m) return 1000;
        return r;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto vec = binaryMatrix.dimensions();
        n = vec[0];
        m = vec[1];
        int ans = 1000;
        for(int i = 0 ; i < n ; i++) {
            ans = min(ans, solve(i, binaryMatrix));
        }
        return ans == 1000 ? -1 : ans;
    }
};
