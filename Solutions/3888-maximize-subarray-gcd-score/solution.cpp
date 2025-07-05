class Solution {
public:
        long long maxGCDScore(vector<int>& A, int k) {
        int n = A.size(), low;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long a = A[i], count = 0, min_pow = INT_MAX;
            for (int j = i; j < n; ++j) {
                a = gcd(a, A[j]);
                int low = A[j] & -A[j];
                if (low < min_pow) {
                    min_pow = low, count = 1;
                } else if (low == min_pow) {
                    count++;
                }
                long long cur = a * ((count <= k) ? 2 : 1) * (j - i + 1);
                res = max(res, cur);
            }
        }
        return res;
    }
};
